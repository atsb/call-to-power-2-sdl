//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : Net functionality (find something better if you don't like this description ;))
//
//----------------------------------------------------------------------------
//
// Disclaimer
//
// THIS FILE IS NOT GENERATED OR SUPPORTED BY ACTIVISION.
//
// This material has been developed at apolyton.net by the Apolyton CtP2
// Source Code Project. Contact the authors at ctp2source@apolyton.net.
//
//----------------------------------------------------------------------------
//
// Compiler flags
//
// _DEBUG
// Generate debug information.
// USE_SDL
// Use SDL API calls
// WIN32
// Use MS Windows32 API calls
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - Added SDL support.
// - Replaced typename T in specialized template member function by the
//   the type for that the function is specialized, by Martin G�hmann.
// - Display the main thread function name in the debugger.
// - Make the Linux version loading and producing Windows compatible
//   savegames. (16-Jan-2019 Martin Gühmann)
//
//----------------------------------------------------------------------------

#include "c3.h"
#include "netfunc.h"
#include "c3files.h"
#include <algorithm>

#if defined(_DEBUG)
#include "debug.h"      	// Os::SetThreadName
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#ifdef WIN32
#include <ras.h>
#endif

#include <algorithm>

namespace
{
    char const  COUNT_MAX   = 255u;
}

/// Operating system dependent wrapper functions
namespace Os
{
    /// Stop the current thread
    /// \param a_Code Code to return to the environment (OS/debugger)
    inline int ExitThread(int a_Code)
    {
#if defined(WIN32)
        ::ExitThread(static_cast<DWORD>(a_Code));
        UNREACHABLE_RETURN(a_Code);
#else
        return a_Code;
#endif
    }
} // namespace Os

int adialup_autodial_enabled(void)
{
	return FALSE;
}

#define adialup_MAXCONNS 10

#ifdef WIN32
typedef DWORD (APIENTRY *pfnRasEnumConnections_t)(LPRASCONN, LPDWORD, LPDWORD);
typedef DWORD (APIENTRY *pfnRasGetConnectStatus_t)(HRASCONN, LPRASCONNSTATUS);
#endif

int adialup_is_active(void)
{
	return FALSE;
}




int adialup_willdial(void)
{
	return adialup_autodial_enabled() && !adialup_is_active();
}

void NETFunc::StringMix(int c, char *mix, char *msg, ...) {
	va_list al;
	va_start(al, msg);
	strcpy(mix, msg);

	char * arg = va_arg(al, char *);
	char str[] = "% ";

	for(int i = 1; i <= c; i++) {
		str[1] = static_cast<char>('0' + i);

		char * next = strstr(mix, str);
		if(next) {
			char *tmp = strdup(next + strlen(str));
			strcpy(next + strlen(arg), tmp);
			strncpy(next, arg, strlen(arg));
			free(tmp);
		}

		arg = va_arg(al, char *);
	}

	va_end(al);
}


char *NETFunc::StringDup(char *s) {
    return (s) ? strcpy(new char[strlen(s) + 1], s) : NULL;
}


NETFunc::Timer::Timer(void)
:
    start   (0),
    finish  (0),
    done    (false)
{
}

void NETFunc::Timer::Start(int d) {
	start = GetTickCount64();
	finish = start + d;
	done = false;
}

bool NETFunc::Timer::Finished(void)
{
    return done || (GetTickCount64() >= finish);
}


NETFunc::MessageHandler::MessageHandler(void) {
	if(hCount < nf_MAX_HANDLERS)
		hList[hCount++] = this;
}

NETFunc::MessageHandler::~MessageHandler(void) {
	Unregister();
}

void NETFunc::MessageHandler::Unregister(void) {
	bool f = false;
	for(int i = 0; i < hCount; i++) {
		if(f)
			hList[i-1] = hList[i];
		else
			f = (hList[i] == this);
	}
	if(f)
		hCount--;
}

bool NETFunc::MessageHandler::HandleAll(Message *m) {
	bool f = false;
	for(int i = 0; i < hCount; i++)
		f = hList[i]->Handle(m) || f;
	return f;
}

NETFunc::MessageHandler *NETFunc::MessageHandler::hList[] = {0};
int NETFunc::MessageHandler::hCount = 0;


NETFunc::Message::Message(CODE c, void *p, size_t s) {
	newbody = true;
	body = new char[s + sizeof(CODE)];
	*(CODE *)body = c;
	memcpy(body + sizeof(CODE), p, s);
	size = s + sizeof(CODE);
	sender = dp_ID_NAMESERVER;
}

NETFunc::Message::Message(CODE c) {
	newbody = true;
	body = new char[sizeof(CODE)];
	*(CODE *)body = c;
	size = sizeof(CODE);
	sender = dp_ID_NAMESERVER;
}

NETFunc::Message::Message(void *p, size_t s, dpid_t id, bool b) {
	newbody = b;
	if(newbody) {
		body = new char[s];
		memcpy(body, p, s);
	} else
		body = (char *)p;
	size = s;
	sender = id;
}

NETFunc::Message::Message(void) {
	newbody = false;
	size = 0;
}

NETFunc::Message::~Message(void) {
	if(newbody)
		delete [] body;
}

dp_packetType_t *NETFunc::Message::Get(void) {
	return (dp_packetType_t *)body;
}

void *NETFunc::Message::GetBody(void) {
	return body + sizeof(CODE);
}

dpid_t NETFunc::Message::GetSender(void) {
	return sender;
}

size_t NETFunc::Message::GetSize(void) {
	return size;
}

size_t NETFunc::Message::GetBodySize(void) {
	return size - sizeof(CODE);
}

NETFunc::Message::CODE NETFunc::Message::GetCode(void) {
	return *(CODE *)body;
}


NETFunc::Messages::Messages(void) {}

NETFunc::Messages::~Messages(void) {
}

void NETFunc::Messages::Push(Message *m) {
	push_back(m);
}

NETFunc::Message *NETFunc::Messages::Pop(void) {
	Message *m = *begin();
	pop_front();
	return m;
}

NETFunc::Messages NETFunc::messages = Messages();


NETFunc::Keys::Keys(void) {
	memset(&curkey, 0, sizeof(KeyStruct));
	curkey.len = 1;
}

void NETFunc::Keys::NextKey(void) {
	if(curkey.buf[curkey.len-1] == COUNT_MAX)
		curkey.len++;
	curkey.buf[curkey.len-1]++;
}


NETFunc::Key::Key(void) {
	memset(&key, 0, sizeof(KeyStruct));
}

NETFunc::Key::Key(Key *k) {
	key = k->key;
}

NETFunc::Key::Key(KeyStruct *k) {
	key = *k;
}
void NETFunc::Key::WriteToFile(FILE *saveFile) const
{
	sint32 first = 0; // For bytes to the first real data
	c3files_fwrite(&first, sizeof(first), 1, saveFile);

	c3files_fwrite(&key.len, sizeof(key.len), 1, saveFile);
	c3files_fwrite(&key.buf, sizeof(key.buf), 1, saveFile);
}

void NETFunc::Key::ReadFromFile(FILE *saveFile)
{
	sint32 first = 0; // For bytes to the first real data
	c3files_fread(&first, sizeof(first), 1, saveFile);

	c3files_fread(&key.len, sizeof(key.len), 1, saveFile);
	c3files_fread(&key.buf, sizeof(key.buf), 1, saveFile);
}

bool NETFunc::Key::Equals(Key *k) {
	return memcmp(&key, &k->key, sizeof(key.len) + key.len) == 0;
}

bool NETFunc::Key::Equals(KeyStruct *k) {
	return memcmp(&key, k, sizeof(key.len) + key.len) == 0;
}

NETFunc::KeyStruct *NETFunc::Key::GetKey(void) {
	return &key;
}


NETFunc::STATUS NETFunc::EnumServers(bool b) {

	return OK;
}


NETFunc::STATUS NETFunc::EnumSessions(bool b) {

	return OK;
}


NETFunc::STATUS NETFunc::EnumPlayers(bool b, KeyStruct *k) {

	return OK;
}


















NETFunc::Server::Server(void) {
	memset(&server, 0, sizeof(dp_serverInfo_t));
}

NETFunc::Server::Server(dp_object_t *o, KeyStruct *k, long f):Key(k) {
	server = o->serv;
}

NETFunc::Server::~Server(void) {
}

char *NETFunc::Server::GetName(void) {
	return server.hostname;
}

int NETFunc::Server::GetPlayers(void) {
	return server.cur_sessTypeUsers;
}

int NETFunc::Server::GetPing(void) {
	return server.rtt_ms_avg;
}

dp_serverInfo_t *NETFunc::Server::GetServer(void) {
	return &server;
}

template<>
bool NETFunc::ListHandler<NETFunc::Server>::Handle(Message *m) {
	if(m->GetCode() == Message::RESET && Equals((KeyStruct *)m->GetBody())) {
		Destroy();
		Clr();
	} else if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(Equals((KeyStruct *)&p->keylen)) {
			Server t(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
			switch(p->status) {

			case dp_RES_CREATED:

			case dp_RES_CHANGED:
				if(p->data.serv.loss_percent != 100)
					if(Find(&t) != end())
						Change(Chg(&t));
					else
						Insert(Add(new Server(t)));

				return true;

			case dp_RES_DELETED:
				Delete(&t);
				Del(&t);
				return true;
			default:
				break;
			}
		}
	}
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::Server>::SetKey(void) {
	key.buf[0] = dp_KEY_SERVERPINGS;


	key.len = 1;
}


NETFunc::Contact::Contact(char *n, char *p) {
	name = NETFunc::StringDup(n);
	number = NETFunc::StringDup(p);
}

NETFunc::Contact::Contact(void) {
}

NETFunc::Contact::~Contact(void) {
	delete name;
	delete number;
}

char *NETFunc::Contact::GetName(void) {
	return name;
}

char *NETFunc::Contact::GetNumber(void) {
	return number;
}

void NETFunc::Contact::SetName(char *n) {
	delete name;
	name = NETFunc::StringDup(n);
}

void NETFunc::Contact::SetNumber(char *p) {
	delete number;
	number = NETFunc::StringDup(p);
}


NETFunc::ContactList::ContactList(void) {

}

NETFunc::ContactList::~ContactList(void) {
}









NETFunc::Port::Port(commPortName_t *p, int b, char *i) {
	port = *p;
	baud	= b;
	strncpy(init, i, nf_PORTINITLEN);
}

NETFunc::Port::Port(void) {
}

NETFunc::Port::~Port(void) {
}

commPortName_t *NETFunc::Port::GetPort(void) {
	return &port;
}

int NETFunc::Port::GetNumber(void) {
	return port.portnum;
}

char *NETFunc::Port::GetName(void) {
	return port.name;
}

int NETFunc::Port::GetBaud(void) {
	return baud;
}

char *NETFunc::Port::GetInit(void) {
	return init;
}


NETFunc::PortList::PortList(Transport *t)
{

}

NETFunc::PortList::PortList(void) {
}

NETFunc::PortList::~PortList(void) {
}

NETFUNC_CONNECT_RESULT NETFunc::ConnectThread(NETFUNC_CONNECT_PARAMETER t)
{
	return 0;
}

NETFUNC_CONNECT_RESULT NETFunc::ReConnectThread(NETFUNC_CONNECT_PARAMETER r)
{
    return 0;
}



































NETFunc::Transport::Transport(const comm_driverInfo_t *d, const dp_transport_t *t, KeyStruct *k)
:
	Key(k),
	transport(*t),
	description(*d)
{

	memset(&parameters, 0, sizeof(commInitReq_t));
	parameters.reqLen = sizeof(commInitReq_t);
	parameters.sessionId = GetTickCount64();
	parameters.dialing_method = comm_INIT_DIALING_METHOD_TONE;
	status = NOSETUP;
}

NETFunc::Transport::Transport(void) {
}

NETFunc::Transport::~Transport(void) {
}

dp_transport_t *NETFunc::Transport::GetTransport(void) {
	return &transport;
}

commInitReq_t *NETFunc::Transport::GetParams(void) {
	return &parameters;
}




NETFunc::STATUS NETFunc::Transport::GetStatus(void) {
	return status;
}

NETFunc::Transport::TYPE NETFunc::Transport::GetType(void) {
	return Transport::UNKNOWN;
}

char *NETFunc::Transport::GetName(void) {
	return description.name;
}

char *NETFunc::Transport::GetFileName(void) {
	return transport.fname;
}

NETFunc::STATUS NETFunc::Transport::SetPort(long p) {
	return BADSETUP;
}

NETFunc::STATUS NETFunc::Transport::SetPort(Port *p) {
	return BADSETUP;
}

NETFunc::STATUS NETFunc::Transport::SetContact(Contact *c) {
	return BADSETUP;
}

NETFunc::TransportSetup::TransportSetup(Transport *t) {

	transport = *t->GetTransport();
	parameters = *t->GetParams();
	status = t->GetStatus();
	parameters.modeministr = StringDup(t->GetParams()->modeministr);
	parameters.phonenum = StringDup(t->GetParams()->phonenum);
	type = t->GetType();
}

NETFunc::TransportSetup::~TransportSetup(void) {

	if ( parameters.modeministr )
		delete [] parameters.modeministr;
	if ( parameters.phonenum )
		delete [] parameters.phonenum;
}

NETFunc::STATUS NETFunc::TransportSetup::GetStatus(void) {
	return status;
}

NETFunc::Transport::TYPE NETFunc::TransportSetup::GetType(void) {
	return type;
}

dp_transport_t *NETFunc::TransportSetup::GetTransport(void) {
	return &transport;
}

commInitReq_t *NETFunc::TransportSetup::GetParams(void) {
	return &parameters;
}

NETFunc::TransportSetup *NETFunc::transport = 0;


NETFunc::Transport::TYPE NETFunc::GetTransportType(const comm_driverInfo_t *c) {
	if((c->needs & (comm_INIT_NEEDS_PORTNUM | comm_INIT_NEEDS_PHONENUM)) == comm_INIT_NEEDS_PORTNUM)
		return Transport::NULLMODEM;
	else if((c->needs & (comm_INIT_NEEDS_PORTNUM | comm_INIT_NEEDS_PHONENUM)) == (comm_INIT_NEEDS_PORTNUM | comm_INIT_NEEDS_PHONENUM))
		return Transport::MODEM;
	else if(c->capabilities & comm_DRIVER_NO_BROADCAST)
		return Transport::INTERNET;
	else
		return Transport::IPX;
}


NETFunc::TransportList::TransportList(void) {

}

NETFunc::TransportList::~TransportList(void) {
}

NETFUNC_CALLBACK_RESULT(void)
NETFunc::TransportList::CallBack(const dp_transport_t *t, const comm_driverInfo_t *d, void *context) {
	if (comm_DRIVER_IS_VISIBLE & d->capabilities) {
		KeyStruct *k = (KeyStruct *)&((TransportList *)context)->key;
		if(k->buf[k->len-1] == COUNT_MAX)
			k->len++;
		else
			k->buf[k->len-1]++;

		switch(GetTransportType(d)) {
		case Transport::INTERNET:
			((TransportList *)context)->Add(new Internet(d, t, k));
		break;
		case Transport::IPX:
			((TransportList *)context)->Add(new IPX(d, t, k));
		break;
		case Transport::MODEM:
			((TransportList *)context)->Add(new Modem(d, t, k));
		break;
		case Transport::NULLMODEM:
			((TransportList *)context)->Add(new NullModem(d, t, k));
		break;
		default:
		break;
		}
	}
}


NETFunc::Internet::Internet(const comm_driverInfo_t *d, const dp_transport_t *t, KeyStruct *k):Transport(d, t, k) {
}

NETFunc::Internet::~Internet(void) {
}

NETFunc::STATUS NETFunc::Internet::SetPort(long p) {
	long o = parameters.portnum;
	parameters.portnum = p;
	return o != p ? RESET : OK;
}

NETFunc::Transport::TYPE NETFunc::Internet::GetType(void) {
	return Transport::INTERNET;
}


NETFunc::IPX::IPX(const comm_driverInfo_t *d, const dp_transport_t *t, KeyStruct *k):Transport(d, t, k) {
	status = READY;
}

NETFunc::IPX::~IPX(void) {
}

NETFunc::Transport::TYPE NETFunc::IPX::GetType(void) {
	return Transport::IPX;
}


NETFunc::Modem::Modem(const comm_driverInfo_t *d, const dp_transport_t *t, KeyStruct *k):Transport(d, t, k) {

}

NETFunc::Modem::~Modem(void) {
}

NETFunc::STATUS NETFunc::Modem::SetContact(Contact *c) {
	if(c)

		parameters.phonenum = c->GetNumber();
	else

		parameters.phonenum = "";
	status = status == NOSETUP ? NOPORT :READY;
	return OK;
}

NETFunc::STATUS NETFunc::Modem::SetPort(Port *p) {

	parameters.baud = p->GetBaud();
	parameters.portnum = p->GetNumber();
	parameters.modeministr = p->GetInit();
	status = status == NOSETUP ? NOCONTACT : READY;
	return OK;
}

NETFunc::Transport::TYPE NETFunc::Modem::GetType(void) {
	return Transport::MODEM;
}


NETFunc::NullModem::NullModem(const comm_driverInfo_t *d, const dp_transport_t *t, KeyStruct *k):Transport(d, t, k) {
}

NETFunc::NullModem::~NullModem(void) {
}

NETFunc::STATUS NETFunc::NullModem::SetPort(Port *p) {

	parameters.baud = p->GetBaud();
	parameters.portnum = p->GetNumber();
	parameters.modeministr = "";
	return OK;
}

NETFunc::Transport::TYPE NETFunc::NullModem::GetType(void) {
	return Transport::NULLMODEM;
}











NETFunc::AIPlayer::AIPlayer(void) {
}

NETFunc::AIPlayer::~AIPlayer(void) {
}

const char *NETFunc::AIPlayer::GetName(void) {
	return name;
}

void NETFunc::AIPlayer::SetName(const char *n) {
	strncpy(name, n, dp_PNAMELEN - 1);
	name[dp_PNAMELEN - 1] = 0;
}

unsigned char NETFunc::AIPlayer::GetGroup(void) {
	return group;
}

void NETFunc::AIPlayer::SetGroup(unsigned char g) {
	group = g;
}

void NETFunc::AIPlayer::SetKey(KeyStruct *k) {
	key = *k;
}

void NETFunc::AIPlayer::Pack(void) {
	Clear();
	Push(key.buf);
	Push(name);
	Push(group);
}

void NETFunc::AIPlayer::Unpack(void) {
	first = body;
	Pop(key.buf);
	key.len = static_cast<short>(strlen(key.buf));
	Pop(name);
	Pop(group);
}

NETFunc::STATUS NETFunc::AIPlayer::Load(FILE *f) {
	if(fread(&(Packet::size), sizeof(SizeT), 1, f) == 1)
		if(fread(body, Packet::size, 1, f) == 1) {
			Unpack();
			return OK;
		}
	return ERR;
}

NETFunc::STATUS NETFunc::AIPlayer::Save(FILE *f) {
	Pack();
	if(fwrite(&(Packet::size), sizeof(SizeT), 1, f) == 1)
		if(fwrite(body, Packet::size, 1, f) == 1)
			return OK;
	return ERR;
}


NETFunc::STATUS NETFunc::AIPlayers::Send(dp_t *p, dpid_t id, dpid_t from) {
	for(iterator i=begin(); i!=end(); i++)
	{
		Message message = Message(Message::ADDAIPLAYER, (*i)->GetBody(), (*i)->GetSize());
		if(NETFunc::Send(p, &message, id, from) != OK)
			return ERR;
	}
	return OK;
}


NETFunc::AIPlayers::AIPlayers(AIPlayers *l):NETFunc::List<NETFunc::AIPlayer>(l) {
}

bool NETFunc::AIPlayers::Handle(Message *m) {
	AIPlayer t;
	if(m->GetCode() == Message::ENTERGAME) {
		Clr();
		return true;
	} else if(m->GetCode() == Message::ADDAIPLAYER) {
		t.Set(m->GetBodySize(), m->GetBody());

		Add(new AIPlayer(t));
		return true;
	} else if(m->GetCode() == Message::DELAIPLAYER) {
		t.Set(m->GetBodySize(), m->GetBody());

		Del(&t);
		return true;
	} else if(m->GetCode() == Message::CHGAIPLAYER) {
		t.Set(m->GetBodySize(), m->GetBody());

		Chg(&t);
		return true;
	}
	return false;
}

bool NETFunc::AIPlayers::Handle(dp_t *p, Message *m, dpid_t from) {
	if(m->GetCode() == Message::PLAYERENTER) {
		Send(p, m->GetSender(), from);
		return true;
	}
	return false;
}

template<>
bool NETFunc::ListHandler<NETFunc::AIPlayer>::Handle(Message *m) {
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::AIPlayer>::SetKey(void) {
}
















void NETFunc::Player::SetGroupMaster(bool b) {
	if(player.bloblen == 0) {
		player.bloblen = 1;
		player.blob[0] = 0;
	}
	if(b)
		player.blob[0] |= nf_GROUPMASTER;
	else
		player.blob[0] &= ~nf_GROUPMASTER;
}

void NETFunc::Player::SetKey(void) {
	key.buf[0] = (char) dpGETSHORT_FIRSTBYTE(player.id);
	key.buf[1] = (char) dpGETSHORT_SECONDBYTE(player.id);
	key.len = 2;
}

NETFunc::Player::Player(void) {
	memset(&player, 0, sizeof(dp_playerId_t));
	player.bloblen = 1;
	SetKey();
	flags = 0;
	muted = false;
}

NETFunc::Player::Player(dp_object_t *o, KeyStruct *k, long f, short l):Key(k) {
	player = o->p;
	SetKey();
	flags = f;
	latency = l;
	muted = false;
}

void NETFunc::Player::Set(dp_playerId_t *p) {
	player = *p;
}

NETFunc::Player::~Player(void) {
}

dpid_t NETFunc::Player::GetId(void) {
	return player.id;
}

char *NETFunc::Player::GetName(void) {
	return player.name;
}

unsigned char *NETFunc::Player::GetBlob(void) {
	return &player.blob[1];
}

unsigned char NETFunc::Player::GetBlobLen(void) {
	if(player.bloblen == 0)
		return 0;
	return player.bloblen - 1;
}

unsigned char NETFunc::Player::GetGroup(void) {
	if(player.bloblen == 0)
		return 0;
	return (player.blob[0] & nf_GROUPNUMBER);
}

short NETFunc::Player::GetLatency(void) {
	return latency;
}

bool NETFunc::Player::IsMe(void) {
	return (flags & dp_OBJECTDELTA_FLAG_LOCAL) != 0;
}

bool NETFunc::Player::IsMuted(void) {
	return muted;
}

void NETFunc::Player::SetMuted(bool m) {
	muted = m;
}

bool NETFunc::Player::IsInCurrentSession(void) {
	return (flags & dp_OBJECTDELTA_FLAG_INOPENSESS) != 0;
}

bool NETFunc::Player::IsHost(void) {
	return (flags & dp_OBJECTDELTA_FLAG_ISHOST) != 0;
}

bool NETFunc::Player::IsGroupMaster(void) {
	return player.bloblen > 0 && GetGroup() && player.blob[0] & nf_GROUPMASTER;
}

bool NETFunc::Player::IsReadyToLaunch(void) {
	return player.bloblen > 0 && player.blob[0] & nf_READYLAUNCH;
}

NETFunc::Player NETFunc::player = Player();
dp_uid_t NETFunc::userId = dp_UID_NONE;

template<>
bool NETFunc::ListHandler<NETFunc::Player>::Handle(Message *m) {
	if(m->GetCode() == Message::RESET) {
		Destroy();
		Clr();
	} else if(m->GetCode() == Message::UPDATE && Equals((KeyStruct *)m->GetBody())) {
		KeyStruct *k = ((KeyStruct *)m->GetBody()) + 1;
		Key key = Key(k);
		for(iterator i=begin(); i!=end(); i++)
			if((*i)->Equals(k)) {
				(*i)->SetMuted(IsMuted(&key));
				Change(Chg(*i));
			}
	} else if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(Equals((KeyStruct *)&p->keylen)) {
			Player t(&p->data, (KeyStruct *)&p->subkeylen, p->flags, p->latency);
			t.SetMuted(IsMuted(&t));
			switch(p->status) {

			case dp_RES_CREATED:

			case dp_RES_CHANGED:
				if(Find(&t) != end())
					Change(Chg(&t));
				else
					Insert(Add(new Player(t)));
				return true;

			case dp_RES_DELETED:
				Delete(&t);
				Del(&t);
				return true;
			default:
				break;
			}
		}
	}
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::Player>::SetKey(void) {
	key.buf[0] = dp_KEY_PLAYERS;
	key.len = 1;
}




NETFunc::PlayerStat::PlayerStat(void) {
	key.len = sizeof(dpid_t);
	name[0] = 0;
	group = 0;
	isingame = true;
	hasleft = false;
}

NETFunc::PlayerStat::~PlayerStat(void) {
}

char *NETFunc::PlayerStat::GetName(void) {
	return name;
}

void NETFunc::PlayerStat::SetName(char *n) {
	strncpy(name, n, dp_PNAMELEN - 1);
	name[dp_PNAMELEN - 1] = 0;
}

unsigned char NETFunc::PlayerStat::GetGroup(void) {
	return group;
}

void NETFunc::PlayerStat::SetGroup(unsigned char g) {
	group = g;
}

void NETFunc::PlayerStat::SetId(dpid_t i) {
	*(dpid_t *)&key.buf = i;
}

dpid_t NETFunc::PlayerStat::GetId(void) {
	return 	*(dpid_t *)&key.buf;
}

void NETFunc::PlayerStat::SetInGame(bool b) {
	isingame = b;
	*((bool *)GetBody() + 1) = b;
}

bool NETFunc::PlayerStat::IsInGame(void) {
	return isingame;
}

void NETFunc::PlayerStat::SetLeft(bool b) {
	hasleft = b;
	*(bool *)GetBody() = b;
}

bool NETFunc::PlayerStat::HasLeft(void) {
	return hasleft;
}

void NETFunc::PlayerStat::Pack(void) {
	Clear();
	Push(hasleft);
	Push(isingame);
	Push(*(dpid_t *)&key.buf);
	Push(name);
	Push(group);
}

void NETFunc::PlayerStat::Unpack(void) {
	first = body;
	Pop(hasleft);
	Pop(isingame);
	Pop(*(dpid_t *)&key.buf);
	Pop(name);
	Pop(group);
}

NETFunc::STATUS NETFunc::PlayerStat::Update(dp_t *p, bool r) {
	hasleft = false;
	isingame = true;
	Pack();
	Message message = Message(Message::ADDPLAYERSTAT, GetBody(), GetSize());
	if(NETFunc::Send(p, &message, dp_ID_BROADCAST, dp_ID_BROADCAST, r) != OK)
		return ERR;
	return OK;
}


NETFunc::PlayerStats::PlayerStats(PlayerStats *l):NETFunc::List<NETFunc::PlayerStat>(l) {
}

NETFunc::STATUS NETFunc::PlayerStats::Send(dp_t *p, dpid_t id, dpid_t from) {
	for(iterator i=begin(); i!=end(); i++)
	{
		Message message = Message(Message::ADDPLAYERSTAT, (*i)->GetBody(), (*i)->GetSize());
		if(NETFunc::Send(p, &message, id) != OK)
			return ERR;
	}
	return OK;
}

void NETFunc::PlayerStats::Left(dpid_t id) {
	PlayerStat t;
	t.SetId(id);
	iterator i = Find(&t);
	if(i != end()) {
		t = **i;
		t.SetLeft(true);
		Chg(&t);
		if(status != RESET)
			PushMessage(new Message(Message::CHGPLAYERSTAT, t.GetBody(), t.GetSize()));
	}
}

bool NETFunc::PlayerStats::Handle(Message *m) {
	PlayerStat t;
	if((m->GetCode() == Message::ENTERGAME && IsHost()) || (m->GetCode() == Message::GAMESESSION && !GotGameSetup())) {
		Clr();
		return true;
	} else if(m->GetCode() == Message::ADDPLAYERSTAT) {
		t.Set(m->GetBodySize(), m->GetBody());
		t.SetInGame(false);

		if(Find(&t) == end())

			Add(new PlayerStat(t));
		else {

			Chg(&t);
			*(Message::CODE *)(m->Get()) = Message::CHGPLAYERSTAT;
		}
		return true;
	} else if(m->GetCode() == Message::DELPLAYERSTAT) {
		t.Set(m->GetBodySize(), m->GetBody());

		Del(&t);
		return true;
	} else if(m->GetCode() == dp_USER_DELPLAYER_PACKET_ID) {
		Left(((dp_playerId_t *)m->GetBody())->id);
		return true;
	} else if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if((p->key[0] == dp_KEY_PLAYERS) && (p->flags & dp_OBJECTDELTA_FLAG_INOPENSESS) && (p->status == dp_RES_DELETED)) {
			Left(p->data.p.id);
			return true;
		}
	}
	return false;
}

bool NETFunc::PlayerStats::Handle(dp_t *p, Message *m, dpid_t from) {
	if(m->GetCode() == Message::PLAYERENTER) {
		Send(p, m->GetSender(), from);
		return true;
	}

	return false;
}




NETFunc::PlayerSetup::PlayerSetup(Player *p):Player(*p) {
	description[0] = 0;
}

NETFunc::PlayerSetup::PlayerSetup() {
	description[0] = 0;
}

NETFunc::PlayerSetup::~PlayerSetup() {
}

void NETFunc::PlayerSetup::SetName(char *n) {
	strncpy(player.name, n, dp_PNAMELEN);
	player.name[dp_PNAMELEN - 1] = 0;
}

void NETFunc::PlayerSetup::SetBlob(char *b) {
	SetBlob((void *)b, strlen(b) + 1);
}

void NETFunc::PlayerSetup::SetBlob(void *b, size_t s) {
    s = std::min<size_t>(s, dp_MAX_PLAYERBLOB_LEN - 1);
	memcpy(&player.blob[1], b, s);
	player.bloblen = static_cast<unsigned char>(s + 1);
}

void NETFunc::PlayerSetup::SetBlobLen(unsigned char l) {
	if(l < dp_MAX_PLAYERBLOB_LEN)
		player.bloblen = l + 1;
}

char *NETFunc::PlayerSetup::GetDescription(void) {
	return description;
}

void NETFunc::PlayerSetup::SetDescription(char *d) {
	strncpy(description, d, nf_PLAYERDESCLEN);
}

void NETFunc::PlayerSetup::SetGroup(char group) {
	if(player.bloblen == 0) {
		player.bloblen = 1;
		player.blob[0] = 0;
	}
	player.blob[0] &= ~nf_GROUPNUMBER;
	player.blob[0] |= (group & nf_GROUPNUMBER);
}

void NETFunc::PlayerSetup::SetReadyToLaunch(bool b) {
	if(player.bloblen == 0) {
		player.bloblen = 1;
		player.blob[0] = 0;
	}
	if(b)
		player.blob[0] |= nf_READYLAUNCH;
	else
		player.blob[0] &= ~nf_READYLAUNCH;
}

void NETFunc::PlayerSetup::Pack() {
	Clear();
	Push(description);
}

void NETFunc::PlayerSetup::Unpack() {
	first = body;
	Pop(description);
}

NETFunc::STATUS NETFunc::PlayerSetup::Load(FILE *f) {
	if(fread(&player, sizeof(dp_playerId_t), 1, f) == 1)
		if(fread(&(Packet::size), sizeof(SizeT), 1, f) == 1)
			if(fread(body, Packet::size, 1, f) == 1) {
				Unpack();
				return OK;
			}
	return ERR;
}

NETFunc::STATUS NETFunc::PlayerSetup::Save(FILE *f) {
	if(fwrite(&player, sizeof(dp_playerId_t), 1, f) == 1) {
		Pack();
		if(fwrite(&(Packet::size), sizeof(SizeT), 1, f) == 1)
			if(fwrite(body, Packet::size, 1, f) == 1)
				return OK;
	}
	return ERR;
}

NETFunc::STATUS NETFunc::PlayerSetup::Update(void) {
	Pack();
	if(SetPlayerSetupPlayer(this) != OK)
		return ERR;
	if(SetPlayerSetupPacket(this) != OK)
		return ERR;
	return OK;
}



































void NETFunc::Session::SetKey() {

}

NETFunc::Session::Session(void) {
	memset(&session, 0, sizeof(dp_session_t));
	session.dwSize = sizeof(dp_session_t);
	session.maxPlayers = dp_MAXREALPLAYERS;
	session.flags = dp_SESSION_FLAGS_CREATESESSION | dp_SESSION_FLAGS_ENABLE_PLAYERVARS;
	session.guidApplication = GameType;
}

NETFunc::Session::Session(dp_object_t *o, KeyStruct *k, long f):Key(k) {
	session = o->sess;
	flags = f;
}

void NETFunc::Session::WriteToFile(FILE *saveFile) const
{
	NETFunc::Key::WriteToFile(saveFile);
	sint32 tmp = 0;

	c3files_fwrite(&session.dwSize, sizeof(session.dwSize), 1, saveFile);
	c3files_fwrite(&session.adrMaster, sizeof(session.adrMaster), 1, saveFile); // 10
	c3files_fwrite(&session.masterPseudoplayer, sizeof(session.masterPseudoplayer), 1, saveFile);
	c3files_fwrite(&session.sessionType, sizeof(session.sessionType), 1, saveFile);
	c3files_fwrite(&session.dwSession, sizeof(session.dwSession), 1, saveFile);
	c3files_fwrite(&session.dwMaxPlayers, sizeof(session.dwMaxPlayers), 1, saveFile);
	c3files_fwrite(&session.dwCurrentPlayers, sizeof(session.dwCurrentPlayers), 1, saveFile);
	c3files_fwrite(&session.dwFlags, sizeof(session.dwFlags), 1, saveFile);
	c3files_fwrite(&session.sessionName, sizeof(session.sessionName), 1, saveFile);
	c3files_fwrite(&session.szUserField, sizeof(session.szUserField), 1, saveFile);
	c3files_fwrite(&session.szPassword, sizeof(session.szPassword), 1, saveFile);

	tmp = static_cast<sint32>(session.dwReserved1); // Long 4 byte or 8 byte
	c3files_fwrite(&tmp, sizeof(tmp), 1, saveFile);

	tmp = static_cast<sint32>(session.dwUser1); // Long 4 byte or 8 byte
	c3files_fwrite(&tmp, sizeof(tmp), 1, saveFile);

	c3files_fwrite(&session.reserved2, sizeof(session.reserved2), 1, saveFile);

	sint8 space = 0; // Spacing in the original implementation
	c3files_fwrite(&space, sizeof(space), 1, saveFile);

	tmp = static_cast<sint32>(flags);
	c3files_fwrite(&tmp, sizeof(tmp), 1, saveFile); // Long 4 byte or 8 byte
}

void NETFunc::Session::ReadFromFile(FILE *saveFile)
{
	NETFunc::Key::ReadFromFile(saveFile);
	sint32 tmp = 0;

	c3files_fread(&session.dwSize, sizeof(session.dwSize), 1, saveFile);
	c3files_fread(&session.adrMaster, sizeof(session.adrMaster), 1, saveFile);
	c3files_fread(&session.masterPseudoplayer, sizeof(session.masterPseudoplayer), 1, saveFile);
	c3files_fread(&session.sessionType, sizeof(session.sessionType), 1, saveFile);
	c3files_fread(&session.dwSession, sizeof(session.dwSession), 1, saveFile);
	c3files_fread(&session.dwMaxPlayers, sizeof(session.dwMaxPlayers), 1, saveFile);
	c3files_fread(&session.dwCurrentPlayers, sizeof(session.dwCurrentPlayers), 1, saveFile);
	c3files_fread(&session.dwFlags, sizeof(session.dwFlags), 1, saveFile);
	c3files_fread(&session.sessionName, sizeof(session.sessionName), 1, saveFile);
	c3files_fread(&session.szUserField, sizeof(session.szUserField), 1, saveFile);
	c3files_fread(&session.szPassword, sizeof(session.szPassword), 1, saveFile);

	c3files_fread(&tmp, sizeof(tmp), 1, saveFile);
	session.dwReserved1 = tmp; // Long 4 byte or 8 byte, for that the anet code must be fixed
	c3files_fread(&tmp, sizeof(tmp), 1, saveFile);
	session.dwUser1 = tmp; // Long 4 byte or 8 byte
	c3files_fread(&session.reserved2, sizeof(session.reserved2), 1, saveFile);

	sint8 space = 0; // Spacing in the original implementation
	c3files_fread(&space, sizeof(space), 1, saveFile);

	c3files_fread(&tmp, sizeof(tmp), 1, saveFile);
	flags = tmp; // Long 4 byte or 8 byte
}

char *NETFunc::Session::GetName(void) {
	return session.sessionName;
}

char *NETFunc::Session::GetPassword(void) {
	return session.szPassword;
}

short NETFunc::Session::GetPlayers(void) {
	return session.currentPlayers;
}

short NETFunc::Session::GetMaxPlayers(void) {
	return session.maxPlayers;
}

short NETFunc::Session::GetFree() {
	return GetMaxPlayers() - GetPlayers();
}

char *NETFunc::Session::GetUserField() {
	return session.szUserField;
}

dp_karma_t NETFunc::Session::GetKarma() {
	return session.karma;
}

bool NETFunc::Session::IsLobby() {
	return (session.flags & dp_SESSION_FLAGS_ISLOBBY) != 0;
}

bool NETFunc::Session::IsServer() {
	return (session.flags & dp_SESSION_FLAGS_ISSERVER) != 0;
}

bool NETFunc::Session::IsClosed() {
	return (session.flags & dp_SESSION_FLAGS_ENABLE_NEWPLAYERS) == 0;
}

bool NETFunc::Session::IsMine(void) {
	return (flags & dp_OBJECTDELTA_FLAG_LOCAL) != 0;
}

bool NETFunc::Session::IsCurrentSession(void) {
	return (flags & dp_OBJECTDELTA_FLAG_INOPENSESS) != 0;
}

NETFunc::Session NETFunc::session = Session();

template<>
bool NETFunc::ListHandler<NETFunc::Session>::Handle(Message *m) {
	if(m->GetCode() == Message::RESET && Equals((KeyStruct *)m->GetBody())) {
		Destroy();
		Clr();
	} else if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(Equals((KeyStruct *)&p->keylen)) {
			Session t(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
			if(t.session.sessionType != GameType)
				return false;
			switch(p->status) {

			case dp_RES_CREATED:

			case dp_RES_CHANGED:
				if(Find(&t) != end())
					Change(Chg(&t));
				else
					Insert(Add(new Session(t)));
				return true;

			case dp_RES_DELETED:
				Delete(&t);
				Del(&t);
				return true;
			default:
				break;
			}
		}
	}
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::Session>::SetKey(void) {
	key.buf[0] = dp_KEY_SESSIONS;
	key.len = 1;
}


NETFunc::Game::Game(void): Session() {
	hostile = false;
}

NETFunc::Game::Game(dp_object_t *o, KeyStruct *k, long f): Session(o, k, f) {
	hostile = false;
}

NETFunc::Game::Game(Session *s): Session(*s) {
	hostile = false;
}

void NETFunc::Game::WriteToFile(FILE *saveFile) const
{
	NETFunc::Session::WriteToFile(saveFile);
	c3files_fwrite(&hostile, sizeof(hostile), 1, saveFile);
}

void NETFunc::Game::ReadFromFile(FILE *saveFile)
{
	NETFunc::Session::ReadFromFile(saveFile);
	c3files_fread(&hostile, sizeof(hostile), 1, saveFile);
}

void NETFunc::Packet::WriteToFile(FILE *saveFile) const
{
	sint32 space = 0; // Add the space from the original implementation
	c3files_fwrite(&space, sizeof(space), 1, saveFile);

	c3files_fwrite(&size, sizeof(size), 1, saveFile);
	c3files_fwrite(&body, sizeof(body), 1, saveFile);

	sint8 littleSpace = 0;
	c3files_fwrite(&littleSpace, sizeof(littleSpace), 1, saveFile);
	c3files_fwrite(&littleSpace, sizeof(littleSpace), 1, saveFile);
	c3files_fwrite(&littleSpace, sizeof(littleSpace), 1, saveFile);
	// Has another size on a 64 bit system, pointers cannot be saved this way anyway
//	c3files_fwrite(&first, sizeof(first), 1, saveFile); // Problem
	sint32 replace = 0;
	c3files_fwrite(&replace, sizeof(replace), 1, saveFile); // Problem
}

void NETFunc::Packet::ReadFromFile(FILE *saveFile)
{
	sint32 space = 0; // Add the space from the original implementation
	c3files_fread(&space, sizeof(space), 1, saveFile);

	c3files_fread(&size, sizeof(size), 1, saveFile);
	c3files_fread(&body, sizeof(body), 1, saveFile);

	sint8 littleSpace = 0;
	c3files_fread(&littleSpace, sizeof(littleSpace), 1, saveFile);
	c3files_fread(&littleSpace, sizeof(littleSpace), 1, saveFile);
	c3files_fread(&littleSpace, sizeof(littleSpace), 1, saveFile);
	// Has another size on a 64 bit system, pointers cannot be saved this way anyway
//	c3files_fread(&first, sizeof(first), 1, saveFile); // Problem
	sint32 replace = 0;
	c3files_fread(&replace, sizeof(replace), 1, saveFile); // Problem

	first = body + size;
}


char NETFunc::Game::GetGroups(void)
{
	return static_cast<char>(session.dwUser1 & nf_GROUPNUMBER);
}

void NETFunc::Game::Set(dp_session_t *s)
{
	session = *s;
}

bool NETFunc::Game::IsLaunched(void) {
	return (session.dwUser1 & nf_LAUNCHED) != 0;
}

bool NETFunc::Game::IsSyncLaunch(void) {
	return (session.dwUser1 & nf_SYNCLAUNCH) != 0;
}

bool NETFunc::Game::IsHostile(void) {
	return hostile;
}

void NETFunc::Game::SetHostile(bool h) {
	hostile = h;
}


NETFunc::Lobby::Lobby(void): Session(), bad(false) {
	strncpy(session.sessionName, LobbyName, dp_SNAMELEN);
	session.flags |= dp_SESSION_FLAGS_ISLOBBY;
}

NETFunc::Lobby::Lobby(dp_object_t *o, KeyStruct *k, long f): Session(o, k, f), bad(false) {
}

void NETFunc::Lobby::SetBad(bool b) {
	bad = b;
}

bool NETFunc::Lobby::IsBad(void) {
	return bad;
}

NETFunc::Lobby NETFunc::lobby = Lobby();

template<>
bool NETFunc::ListHandler<NETFunc::Lobby>::Handle(Message *m) {
	if(m->GetCode() == Message::RESET && Equals((KeyStruct *)m->GetBody())) {
		Destroy();
		Clr();
	} else if(m->GetCode() == Message::LOBBYDELTAPACKET) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(Equals((KeyStruct *)&p->keylen)) {
			Lobby t(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
			if(t.session.sessionType != GameType)
				return false;
			switch(p->status) {

			case dp_RES_CREATED:

			case dp_RES_CHANGED:
				if(Find(&t) != end())
					Change(Chg(&t));
				else
					Insert(Add(new Lobby(t)));
				return true;

			case dp_RES_DELETED:
				Delete(&t);
				Del(&t);
				return true;
			default:
				break;
			}
		}
	}
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::Lobby>::SetKey(void) {
	key.buf[0] = dp_KEY_SESSIONS;
	key.len = 1;
}

template<>
bool NETFunc::ListHandler<NETFunc::Game>::Handle(Message *m) {
	if(m->GetCode() == Message::RESET && Equals((KeyStruct *)m->GetBody())) {
		Destroy();
		Clr();
	} else if(m->GetCode() == Message::UPDATE && Equals((KeyStruct *)m->GetBody())) {
		KeyStruct *k = ((KeyStruct *)m->GetBody()) + 1;
		Key key = Key(k);
		for(iterator i=begin(); i!=end(); i++)
			if((*i)->Equals(k)) {
				(*i)->SetHostile(IsHostile(&key));
				Change(Chg(*i));
			}
	} else if(m->GetCode() == Message::GAMEDELTAPACKET) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(Equals((KeyStruct *)&p->keylen)) {
			Game t(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
			if(t.session.sessionType != GameType)
				return false;
			t.SetHostile(IsHostile(&t));
			switch(p->status) {

			case dp_RES_CREATED:

			case dp_RES_CHANGED:
				if(Find(&t) != end())
					Change(Chg(&t));
				else
					Insert(Add(new Game(t)));
				return true;

			case dp_RES_DELETED:
				Delete(&t);
				Del(&t);
				return true;
			default:
				break;
			}
		}
	}
	return false;
}

template<>
void NETFunc::ListHandler<NETFunc::Game>::SetKey(void) {
	key.buf[0] = dp_KEY_SESSIONS;
	key.len = 1;
}


NETFunc::PlayerList::PlayerList(void) {
	count++;
	if(!players)
		players = new Players();
}

NETFunc::PlayerList::~PlayerList() {
	count--;
	if(!count) {
		delete players;
		players = 0;
	}
}

void NETFunc::PlayerList::SetKey(KeyStruct *k) {
	if(players)
		players->SetKey(k);
}

NETFunc::Player *NETFunc::PlayerList::FindPlayer(dpid_t id) {
	Players::iterator i;
	for(i = players->begin(); i!=players->end(); i++)
		if((*i)->GetId() == id)
			return *i;
	return 0;
};

NETFunc::PlayerList::Players *NETFunc::PlayerList::players = 0;
int NETFunc::PlayerList::count = 0;

NETFunc::GameSetup::GameSetup() {
	description[0] = 0;
}

NETFunc::GameSetup::GameSetup(Game *g):Game(*g), Packet() {
	description[0] = 0;
}

NETFunc::GameSetup::~GameSetup() {
}

void NETFunc::GameSetup::WriteToFile(FILE *saveFile) const
{
	NETFunc::Game::WriteToFile(saveFile);
	sint8 space = 0; // Add the space from the original implementation
	c3files_fwrite(&space, sizeof(space), 1, saveFile);
	c3files_fwrite(&space, sizeof(space), 1, saveFile);
	c3files_fwrite(&space, sizeof(space), 1, saveFile);
	NETFunc::Packet::WriteToFile(saveFile);
	c3files_fwrite(&description, sizeof(description), 1, saveFile);
}

void NETFunc::GameSetup::ReadFromFile(FILE *saveFile)
{
	NETFunc::Game::ReadFromFile(saveFile);
	sint8 space = 0; // Add the space from the original implementation
	c3files_fread(&space, sizeof(space), 1, saveFile);
	c3files_fread(&space, sizeof(space), 1, saveFile);
	c3files_fread(&space, sizeof(space), 1, saveFile);
	NETFunc::Packet::ReadFromFile(saveFile);
	c3files_fread(&description, sizeof(description), 1, saveFile);
}

char *NETFunc::GameSetup::GetDescription(void) {
	return description;
}

void NETFunc::GameSetup::SetDescription(char *d) {
	strncpy(description, d, nf_GAMEDESCLEN);
}

void NETFunc::GameSetup::SetGroups(char groups) {
	session.dwUser1 &= ~nf_GROUPNUMBER;
	session.dwUser1 |= (groups & nf_GROUPNUMBER);
}

void NETFunc::GameSetup::SetName(char *n) {
	strncpy(session.sessionName, n, dp_SNAMELEN);
}

void NETFunc::GameSetup::SetPassword(char *p) {
	strncpy(session.szPassword, p, dp_PASSWORDLEN);
}

void NETFunc::GameSetup::SetSize(short s) {
	session.maxPlayers = s;
}

void NETFunc::GameSetup::SetUserField(char *u) {
	SetUserField((void *)u, strlen(u) + 1);
}

void NETFunc::GameSetup::SetUserField(void *u, size_t s) {
	memcpy(session.szUserField, u, std::min<size_t>(s, dp_USERFIELDLEN));
}

void NETFunc::GameSetup::SetLaunched(bool b) {
	if(b)
		session.dwUser1 |= nf_LAUNCHED;
	else
		session.dwUser1 &= ~nf_LAUNCHED;
}

void NETFunc::GameSetup::SetSyncLaunch(bool s) {
	if(s)
		session.dwUser1 |= nf_SYNCLAUNCH;
	else
		session.dwUser1 &= ~nf_SYNCLAUNCH;
}

void NETFunc::GameSetup::SetClosed(bool c) {
	if(c)
		session.flags &= ~dp_SESSION_FLAGS_ENABLE_NEWPLAYERS;
	else
		session.flags |= dp_SESSION_FLAGS_ENABLE_NEWPLAYERS;
}

void NETFunc::GameSetup::Pack() {
	Clear();
	Push(description);
}

void NETFunc::GameSetup::Unpack() {
	first = body;
	Pop(description);
}

NETFunc::STATUS NETFunc::GameSetup::Send(dp_t *p, dpid_t id, dpid_t from) {

	return OK;
}

bool NETFunc::GameSetup::Handle(Message *m) {

	return false;
}

bool NETFunc::GameSetup::Handle(dp_t *p, Message *m, dpid_t from) {

	return false;
}

NETFunc::STATUS NETFunc::GameSetup::Load(FILE *f) {
	return OK;
}

NETFunc::STATUS NETFunc::GameSetup::Save(FILE *f) {
	return OK;
}

NETFunc::STATUS NETFunc::GameSetup::Update(bool b) {

	return OK;
}




NETFunc::STATUS	NETFunc::Chat::Send(Player *p, char *m) {
	return OK;
}

NETFunc::STATUS	NETFunc::Chat::SendGroup(char *m) {
	return OK;
}

bool NETFunc::Chat::Handle(Message *m) {

	return false;
}

NETFunc::Lobby *NETFunc::Lobbies::FindBest(void) {
	iterator i;
	Lobby *l, *lobby = 0;

	return lobby;
}

void NETFunc::Lobbies::Reset(void) {

}

NETFunc::Players::Players(Players *l):NETFunc::List<NETFunc::Player>(l) {
}

bool NETFunc::Players::ReadyToLaunch(void) {

	return true;
};

NETFunc::Player *NETFunc::Players::FindGroupMate(char g) {

	return 0;
};

NETFunc::Player *NETFunc::Players::FindGroupMaster(char g) {

	return 0;
};

char NETFunc::Players::FindSmallestGroup(void) {
	char sg = 0;

	return sg;
};

bool NETFunc::Players::Handle(Message *m) {

	return false;
}

bool NETFunc::Hostiles::Check(Key *s) {

	return false;
}

NETFunc::Hostiles NETFunc::hostiles = Hostiles();

bool NETFunc::Mutes::Check(Key *p) {

	return false;
}

NETFunc::Mutes NETFunc::mutes = Mutes();


NETFunc::NETFunc(void) {

}

NETFunc::STATUS NETFunc::Connect(char *file) {

	return OK;
}

NETFunc::~NETFunc(void) {

}

NETFunc::STATUS NETFunc::GetStatus(void) {
	return status;
}

bool NETFunc::Connected(void) {
	return connected;
}

dp_t *NETFunc::GetDP(void) {
	return dp;
}

NETFunc::Session *NETFunc::GetSession(void) {
	return &session;
}

NETFunc::Player *NETFunc::GetPlayer(void) {
	return &player;
}

NETFunc::TransportSetup *NETFunc::GetTransport(void) {
	return transport;
}

NETFunc::STATUS NETFunc::SetTransport(Transport *t) {
	return OK;
}


NETFunc::STATUS NETFunc::SetPlayerSetup(PlayerSetup *p) {
	return OK;
}

NETFunc::STATUS NETFunc::SetPlayerSetupPacket(PlayerSetup *p) {
	return OK;
}

NETFunc::STATUS NETFunc::SetPlayerSetupPlayer(PlayerSetup *p) {
	return OK;
}

NETFunc::STATUS NETFunc::GetPlayerSetupPacket(Player *p) {

	return OK;
}

NETFunc::STATUS NETFunc::SetReadyToLaunch(bool b) {
	return OK;
}

NETFunc::STATUS NETFunc::SetGroupMaster(Player *p) {
	return OK;
}

NETFunc::STATUS NETFunc::SetRemotePlayerRecord(PlayerSetup *p) {
	return OK;
}

NETFunc::STATUS NETFunc::SetRemotePlayerPacket(PlayerSetup *p) {
	return OK;
}


NETFunc::STATUS NETFunc::SetGameSetup(GameSetup *g) {
	return OK;
}

NETFunc::STATUS NETFunc::SetGameSetupPacket(GameSetup *g) {
	return OK;
}

NETFunc::STATUS NETFunc::SetGameSetupSession(GameSetup *g) {
	return OK;
}

NETFunc::STATUS NETFunc::InsertAIPlayer(AIPlayer *p) {
	return OK;
}

NETFunc::STATUS NETFunc::DeleteAIPlayer(AIPlayer *p) {
	return OK;
}

NETFunc::STATUS NETFunc::ChangeAIPlayer(AIPlayer *p) {
	return OK;
}

NETFunc::STATUS NETFunc::Launch() {
	return OK;
}

NETFunc::STATUS NETFunc::UnLaunchAll() {
	return OK;
}

NETFunc::STATUS NETFunc::Login(char *username, char *password) {
	return OK;
}

NETFunc::STATUS NETFunc::SetServer(Server *s) {

	return ERR;
}

bool NETFunc::NeedUpdate(void) {

	return false;
}

NETFunc::STATUS NETFunc::DoUpdate(void) {

	return OK;
}

void NETFunc::SetHost(bool h) {
	host = h;
}

bool NETFunc::GotGameSetup() {
	return gotgame && gotgamepacket;
}

bool NETFunc::IsHost() {
	return host;








}

bool NETFunc::IsHostile(Key *s) {
	return hostiles.Check(s);
}

bool NETFunc::IsMuted(Key *p) {
	return mutes.Check(p);
}

void NETFunc::Mute(Key *p, bool m) {
	KeyStruct keys[2];
	keys[0].buf[0] = dp_KEY_PLAYERS;
	memcpy(&keys[0].buf[1], &session.key.buf[0], session.key.len);
	keys[0].len = session.key.len + 1;
	memcpy(&keys[1], &p->key, sizeof(KeyStruct));
	if(m) {
		if(mutes.Find(p) == mutes.end())
			mutes.Add(new Key(*p));
	} else
		mutes.Del(p);

	PushMessage(new Message(Message::UPDATE, &keys[0], (sizeof(KeyStruct)<<1)));
}

NETFunc::STATUS NETFunc::Connect() {

	if(!playerset)
		return ERR;

	if(status == READY) {

		if(transport && transport->GetType() == Transport::INTERNET) {
			timer.Start(1000);
			status = WAITDELAY;
			nextStatus = OPENLOBBY;

		} else {
			EnumSessions(false);
			EnumSessions(true);
			timer.Start(2000);
			status = WAITDELAY;
			nextStatus = OPENLOBBY;
		}
		return OK;
	}
	return ERR;
}

NETFunc::STATUS NETFunc::Connect(dp_t *d, PlayerStats *stats, bool h) {

	
	return OK;
}

void NETFunc::ReConnect(void) {
	
}

NETFunc::STATUS NETFunc::Reset() {

	if(!playerset)
		return ERR;
	status = READY;
	messages.clear();


	return OK;
}

NETFunc::STATUS NETFunc::Join(Game *g, char *password) {

	if(g->IsCurrentSession())
		return ERR;

	if(status == OK) {

		if(strlen(g->GetPassword()) != strlen(password) || strncmp(g->GetPassword(), password, dp_SNAMELEN)) {

			return BADPASSWORD;

		} else if(g->GetFree() && !g->IsClosed() && !g->IsHostile()) {
			Close();
			*(Game *)&gameSetup = *g;
			host = false;
			game = true;
			launch = false;
			launched = false;
			canlaunch = false;
			gotgame = false;
			gotgamepacket = false;
			session= *(Session *)g;
			nextStatus = OPENSESSION;
			return OK;
		} else
			return ERR;
	}
	return BUSSY;
}

NETFunc::STATUS NETFunc::Join(Lobby *l) {

	if(l->IsCurrentSession())
		return ERR;

	if(status == OK) {

		if(l->GetFree()) {
			Close();
			game = false;
			session = *(Session *)l;
			nextStatus = OPENSESSION;
			return OK;
		} else
			return ERR;
	}
	return BUSSY;
}

NETFunc::STATUS NETFunc::Create(GameSetup *g) {
	if(!playerset)
		return ERR;

	if(status == OK) {
		Close();
		g->SetLaunched(false);
		gameSetup = *g;
		host = true;
		game = true;
		launch = false;
		launched = false;
		canlaunch = !gameSetup.IsSyncLaunch();
		gotgame = true;
		gotgamepacket = true;
		setgame = false;
		setgamepacket = false;

		session = *(Session *)g;
		session.session.flags = dp_SESSION_FLAGS_CREATESESSION | dp_SESSION_FLAGS_ENABLE_PLAYERVARS;
		nextStatus = OPENSESSION;
		return OK;
	}
	return BUSSY;
}

NETFunc::STATUS NETFunc::Leave(void) {
	game = false;
	host = false;
	launch = false;
	launched = false;
	canlaunch = false;
	SetPlayerSetup(&playerSetup);
	Close();
	nextStatus = OPENLOBBY;
	return OK;
}

NETFunc::STATUS NETFunc::Disconnect(void) {

	return OK;
}

NETFunc::STATUS NETFunc::Quit(void) {

	return OK;
}

NETFunc::STATUS NETFunc::Send(dp_t *p, Message *m, dpid_t id, dpid_t from, bool r) {

	return OK;
}

bool NETFunc::Handle(Message *m) {
	if(aiPlayers)
		aiPlayers->Handle(m);
	if(playerStats)
		playerStats->Handle(m);
	gameSetup.Handle(m);
	players.Handle(m);

	if(host && game) {
		gameSetup.Handle(dp, m);
		if(aiPlayers)
			aiPlayers->Handle(dp, m);
		if(playerStats)
			playerStats->Handle(dp, m);

		if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
			dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
			if(p->key[0] == dp_KEY_PLAYERS) {
				Player t = Player(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
				if(p->flags & dp_OBJECTDELTA_FLAG_INOPENSESS) {
					if(p->status == dp_RES_DELETED || p->status == dp_RES_CREATED) {
						gameSetup.SetGroups(players.size() + (aiPlayers ? aiPlayers->size() : 0));
						SetGameSetupSession(&gameSetup);
					}
				}
			}
		} else if(m->GetCode() == Message::ADDAIPLAYER || m->GetCode() == Message::CHGAIPLAYER || m->GetCode() == Message::DELAIPLAYER) {
			gameSetup.SetGroups(players.size() + (aiPlayers ? aiPlayers->size() : 0));
			SetGameSetupSession(&gameSetup);
		}

	}

	if(m->GetCode() == dp_ACCOUNT_PACKET_ID) {
		dp_account_packet_t *p = (dp_account_packet_t *)m->GetBody();
		userId = p->uid;
		if(p->reason == dp_RES_OK && status == LOGIN) {
			PushMessage(new Message(Message::LOGINOK));
		} else {
			PushMessage(new Message(Message::LOGINERR));
		}
		return true;
	} else if(m->GetCode() == Message::LOGINOK) {
		EnumServers(false);
		status = READY;
		return true;
	} else if(m->GetCode() == Message::PLAYERENTER) {
		dp_playerId_t *p = (dp_playerId_t *)m->GetBody();
		Message message = Message(Message::PINGBACK);
		Send(dp, &message, p->id);
		return true;
	}
	else if(m->GetCode() == Message::RESET) {
		if(((KeyStruct *)m->GetBody())->buf[0] == dp_KEY_SESSIONS)
			lobbies.Clr();
		return true;
	} else if(m->GetCode() == dp_USER_HOST_PACKET_ID) {
		host = true;
		if(!gameSetup.IsSyncLaunch())
			canlaunch = true;
		PushMessage(new Message(Message::GAMEHOST));
		return true;
	} else if(m->GetCode() == Message::UNLAUNCH) {
		launch = false;
		launched = false;
		playerSetup.SetReadyToLaunch(false);
		SetPlayerSetupPlayer(&playerSetup);
		return true;
	} else if(m->GetCode() == dp_SESSIONLOST_PACKET_ID) {
		status = CLOSE;
		nextStatus = OPENLOBBY;

		PushMessage(new Message(Message::SESSIONERR));
		return true;
	} else if(m->GetCode() == Message::GAMESESSION || m->GetCode() == Message::GAMEPACKET) {
		if(gameSetup.IsLaunched() && GotGameSetup())
			canlaunch = true;
		return true;
	} else if(m->GetCode() == Message::SETPLAYERRECORD) {
		playerSetup.Player::Set((dp_playerId_t *)m->GetBody());
		player.Set((dp_playerId_t *)m->GetBody());
		SetPlayerSetupPlayer(&playerSetup);
		return true;
	} else if(m->GetCode() == Message::SETPLAYERPACKET) {
		playerSetup.Packet::Set(m->GetBodySize(), m->GetBody());
		SetPlayerSetupPacket(&playerSetup);
		return true;
	} else if(m->GetCode() == Message::KICKED) {






		PushMessage(new Message(Message::PLAYERKICK));

		Leave();
	} else if(m->GetCode() == dp_OBJECTDELTA_PACKET_ID) {
		dp_objectDelta_packet_t *p = (dp_objectDelta_packet_t *)m->GetBody();
		if(p->key[0] == dp_KEY_SESSIONS) {
			Session s = Session(&p->data, (KeyStruct *)&p->subkeylen, p->flags);

			if(s.session.sessionType == GameType)
			if(s.IsLobby()) {
				*(Message::CODE *)(m->body) = Message::LOBBYDELTAPACKET;
				Lobby l(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
				switch(p->status) {

				case dp_RES_CREATED:
					lobbies.Add(new Lobby(l));
					break;

				case dp_RES_DELETED:
					lobbies.Del(&l);
					break;

				case dp_RES_CHANGED:
					lobbies.Chg(&l);
					break;
				default:
					break;
				}
			} else
				*(Message::CODE *)(m->body) = Message::GAMEDELTAPACKET;

			if( ( s.Equals(&session) || s.IsCurrentSession() )
				&& (p->status == dp_RES_CREATED || p->status == dp_RES_CHANGED)) {
				if((session.session.flags & dp_OBJECTDELTA_FLAG_INOPENSESS) == 0) {
					p->flags |= dp_OBJECTDELTA_FLAG_INOPENSESS;
					mutes.Clr();
					players.Clr();
				}
				s.flags |= dp_OBJECTDELTA_FLAG_INOPENSESS;
				session = s;
			}
			return true;
		} else if(p->key[0] == dp_KEY_PLAYERS) {
			Player t = Player(&p->data, (KeyStruct *)&p->subkeylen, p->flags);
			if(p->flags & dp_OBJECTDELTA_FLAG_LOCAL) {
				if(p->status == dp_RES_DELETED) {











				} else if(p->status == dp_RES_CREATED || p->status == dp_RES_CHANGED) {

					player = t;
					if(status == READY) {
						status = OK;

						PushMessage(new Message(Message::ENTERGAME, session.GetKey(), sizeof(KeyStruct)));
					}
					if(p->status == dp_RES_CREATED) {
						Message message = Message(Message::PLAYERENTER, &player.player, sizeof(dp_playerId_t));
						Send(dp, &message, dp_ID_BROADCAST);
					}
				}
			}

			if(p->flags & dp_OBJECTDELTA_FLAG_INOPENSESS) {
				if(p->status == dp_RES_DELETED)
					mutes.Del(&t);

				if(host && gameSetup.IsSyncLaunch()) {

					canlaunch = players.ReadyToLaunch() && GotGameSetup() &&
						!(t.IsHost() && p->status == dp_RES_DELETED);
				}
				return true;
			}
		}
	}
	return false;
}

void NETFunc::Execute(void) {
	
}

NETFUNC_CALLBACK_RESULT(int)
NETFunc::SessionCallBack(dp_session_t *s, long *pTimeout, long flags, void *context) {

	return 0;
}

NETFUNC_CALLBACK_RESULT(void)
NETFunc::PlayerCallBack(dpid_t id, dp_char_t *n, long flags, void *context) {

	if(n) {

		strcpy(((NETFunc *)context)->player.player.name, n);
		((NETFunc *)context)->player.player.id = id;
		((NETFunc *)context)->player.SetKey();
		((NETFunc *)context)->status = OK;

		strncpy(playername, n, dp_PNAMELEN);

		if(((NETFunc *)context)->session.IsLobby())
			PushMessage(new Message(Message::ENTERLOBBY, ((NETFunc *)context)->session.GetKey(), sizeof(KeyStruct)));
		else
			PushMessage(new Message(Message::ENTERGAME, ((NETFunc *)context)->session.GetKey(), sizeof(KeyStruct)));
	} else {
		((NETFunc *)context)->status = CLOSE;
		((NETFunc *)context)->nextStatus = OPENLOBBY;

		PushMessage(new Message(Message::SESSIONERR));
	}
}

void NETFunc::CancelDial(void) {
	cancelDial = 1;
}

NETFunc::STATUS NETFunc::Kick(Player *p) {
	if(status == OK && p->IsInCurrentSession() && !p->IsMe())
		if(player.IsHost()){
			Message message = Message(Message::KICKED);
			return Send(dp, &message, p->GetId(), player.GetId());
		}

		else if(player.IsGroupMaster() && player.GetGroup() == p->GetGroup())
		{
			Message message = Message(Message::KICKED);
			return Send(dp, &message, p->GetId(), player.GetId());
		}
	return ERR;
}

NETFunc::STATUS NETFunc::Close(void) {




		session = Session();
		setplayer = true;
		setplayerpacket = true;


		mutes.Clr();
		players.Clr();
		status = CLOSE;
		return OK;

}































bool NETFunc::HandleMessage(Message *m) {
	return MessageHandler::HandleAll(m);
}

void NETFunc::Receive(void) {

}

NETFunc::Message *NETFunc::GetMessage(void) {

	Execute();

	Receive();

	Message *m = 0;

	if(!messages.empty()) {
		m = messages.Pop();
		Handle(m);
	}
	return m;
}

void NETFunc::PushChatMessage(char *m) {
	size_t size = strlen(m) + 1;
	char buffer[dpio_MAXLEN_UNRELIABLE];
	*(Chat::TYPE *)buffer = Chat::SYSTEM;
	memcpy(buffer + sizeof(Chat::TYPE), m , size);
	size += sizeof(Chat::TYPE);
	PushMessage(new Message(Message::CHAT, buffer, size));
}

void NETFunc::PushMessage(Message *m) {
	messages.Push(m);
}

dp_t *NETFunc::dp = 0;

dp_result_t	NETFunc::result = 0;

char NETFunc::buffer[dpio_MAXLEN_UNRELIABLE] = "";

size_t NETFunc::size = 0;

dpid_t NETFunc::source = 0;

NETFunc::STATUS NETFunc::status = RESET;

dpid_t NETFunc::destination = 0;

dp_species_t NETFunc::GameType = 0;

char *NETFunc::LobbyName = "Lobby";

char *NETFunc::DllPath = "anet";

int NETFunc::PlayerSetupPacketKey = 0;

long NETFunc::cancelDial = 0;

bool NETFunc::connected = false;

bool NETFunc::reconnected = true;

NETFunc::PlayerSetup NETFunc::playerSetup = NETFunc::PlayerSetup();

bool NETFunc::playerset = false;

bool NETFunc::setplayerpacket = false;

bool NETFunc::setplayer = false;

NETFunc::GameSetup NETFunc::gameSetup = NETFunc::GameSetup();

bool NETFunc::game = false;

bool NETFunc::host = false;

bool NETFunc::launch = false;

bool NETFunc::launched = false;

bool NETFunc::canlaunch = false;

bool NETFunc::setgamepacket = false;

bool NETFunc::setgame = false;

bool NETFunc::gotgamepacket = false;

bool NETFunc::gotgame = false;

char NETFunc::servername[64] = "";
char NETFunc::playername[dp_PNAMELEN] = "";
char NETFunc::sessionname[dp_SNAMELEN] = "";
