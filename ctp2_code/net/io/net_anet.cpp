#include "c3.h"
#include "net_io.h"
#include "net_anet.h"
#include "net_util.h"
#include "net_types.h"

#include "anet.h"

#include "netfunc.h"
#include "netshell.h"

extern NETFunc *g_netfunc;

#define HOST_ID dppt_MAKE('H', 'I')
#define ADDME_ID dppt_MAKE('A', 'M')




ActivNetIO::ActivNetIO()
{

}

ActivNetIO::~ActivNetIO()
{
	
}

void dp_PASCAL anet_EnumPlayers(dpid_t id,
								dp_char_t *name,
								long flags,
								void *context)
{

}

void ActivNetIO::PlayerCallback(dpid_t id,
								dp_char_t *name,
								long flags)
{
	
}

void ActivNetIO::SetDP(dp_t *dp)
{
	

}

void dp_PASCAL anet_EnumTransportsCallback(const dp_transport_t *fname,
							  const comm_driverInfo_t *description,
							  void* context)
{


}


void
ActivNetIO::TransportCallback(const dp_transport_t *fname,
							   const comm_driverInfo_t *description)
{

}

NET_ERR
ActivNetIO::EnumTransports()
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::SetTransport(sint32 trans_id)

{
	return NET_ERR_OK;
}

int dp_PASCAL anet_CreateSessionCallback(dp_session_t *ps,
					long *pTimeout,
					long flags,
					void* context)
{

	return 0;
}

void dp_PASCAL anet_PlayerReadyCallback(dpid_t id, dp_char_t *name,
					long flags, void *context)
{


}

void
ActivNetIO::PlayerReady(dpid_t id, dp_char_t * name, sint32 flags)
{

}

sint32
ActivNetIO::SessionReadyCallback(dp_session_t *ps,
				  long * pTimeout,
				  long flags)
{
	return 0;
}

NET_ERR
ActivNetIO::Host(char* sessionName)
{
	return NET_ERR_OK;
}

int dp_PASCAL anet_EnumSessionsCallback(dp_session_t *sDesc,
					long *pTimeout,
					long flags,
					void* context)
{

	return 0;
}

sint32
ActivNetIO::SessionCallback(dp_session_t *sDesc,
			long *pTimeout,
			long flags)
{
	return 0;
}

NET_ERR
ActivNetIO::EnumSessions()
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::Join(sint32 sesindex)
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::GetMyId(uint16 & id)
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::GetHostId(uint16 & id)
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::EnumPlayers()
{

	return NET_ERR_NOTIMPLEMENTED;
}

NET_ERR
ActivNetIO::Send(uint16 id,
				 sint32 flags,
				 uint8* buf,
				 sint32 len)
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::Idle()
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::SetName(char* name)
{
	return NET_ERR_OK;
}

NET_ERR
ActivNetIO::SetLobby(char* serverName)
{
	return NET_ERR_OK;
}

BOOL ActivNetIO::ReadyForData()
{
	return 0;
}

NET_ERR ActivNetIO::SetMaxPlayers(uint16 players, bool lock)
{
	return NET_ERR_OK;
}

NET_ERR ActivNetIO::KickPlayer(uint16 player)
{
	return NET_ERR_OK;
}

NET_ERR ActivNetIO::Reset()
{
	return NET_ERR_NOTIMPLEMENTED;
}
