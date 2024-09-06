
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "DiplomacyThreatRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"


CTPDatabase<DiplomacyThreatRecord> *g_theDiplomacyThreatDB = NULL;

void DiplomacyThreatRecord::Init()
{
    m_flags0 = 0;
    m_Title = 0;
    m_Type = NULL;
    m_Arg1 = 0;
    m_Details = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void DiplomacyThreatRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_flags0;
        {
            MBCHAR* tmpString = g_theStringDB->GetIdStr(m_Title);
            archive << tmpString;
        }

        archive << m_Type;
        archive << m_Arg1;
        {
            MBCHAR* tmpString = g_theStringDB->GetIdStr(m_Details);
            archive << tmpString;
        }

    } else {
        //GovMod Specific flag initialization
        m_hasGovernmentsModified = false;

        archive >> m_index;
        {
            MBCHAR* tmpStr = NULL;
            archive >> tmpStr;
            g_theStringDB->GetStringID(tmpStr, m_name);
            SetTextName(g_theStringDB->GetNameStr(m_name));
        }
        archive >> m_flags0;
        {
            MBCHAR* tmpString = NULL;
            archive >> tmpString;
            g_theStringDB->GetStringID(tmpString, m_Title);
            delete[] tmpString;
        }

        m_Type = NULL;
        archive >> m_Type;

        archive >> m_Arg1;
        {
            MBCHAR* tmpString = NULL;
            archive >> tmpString;
            g_theStringDB->GetStringID(tmpString, m_Details);
            delete[] tmpString;
        }

    }
}

DiplomacyThreatRecord::~DiplomacyThreatRecord()
{
    delete m_Type;
}

DiplomacyThreatRecord const & DiplomacyThreatRecord::operator = (DiplomacyThreatRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_flags0 = rval.m_flags0;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        m_Title = rval.m_Title;

        delete [] m_Type;
        m_Type = NULL;

        if (rval.m_Type)
        {
            m_Type = new char [strlen(rval.m_Type)+1];
            strcpy(m_Type, rval.m_Type);
        }

        m_Arg1 = rval.m_Arg1;

        m_Details = rval.m_Details;

    }

    return *this;
}

const char *g_DiplomacyThreat_Tokens[] =
{
    "Title",
    "Type",
    "Arg1",
    "Details",
    "Disabled",
    "HasAlly",
    "HasBorderIncursion",
    "IsPirating",
    "HasEmbassy",
    "HasHotwar",
    "NoHotwar",
    "HasPeaceTreaty",
    "HasAlliance",
    "HasNuclearWeapons",
    "HasBioWeapons",
    "HasNanoWeapons",
    "HasEmbargo",
    "HasMilitaryAgreement",
    "HasPollutionAgreement",
    "HasPollution",
};

DiplomacyThreatRecordAccessorInfo g_DiplomacyThreatRecord_Accessors[] =
{
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* Title */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* Type */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* Arg1 */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* Details */
    { NULL, &DiplomacyThreatRecord::GetDisabled, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasAlly, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasBorderIncursion, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetIsPirating, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasEmbassy, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasHotwar, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetNoHotwar, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasPeaceTreaty, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasAlliance, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasNuclearWeapons, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasBioWeapons, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasNanoWeapons, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasEmbargo, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasMilitaryAgreement, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasPollutionAgreement, NULL, NULL, NULL, NULL, NULL },
    { NULL, &DiplomacyThreatRecord::GetHasPollution, NULL, NULL, NULL, NULL, NULL },
};

#define k_Token_DiplomacyThreat_Title            ((k_Token_Custom_Base) + 0)
#define k_Token_DiplomacyThreat_Type             ((k_Token_Custom_Base) + 1)
#define k_Token_DiplomacyThreat_Arg1             ((k_Token_Custom_Base) + 2)
#define k_Token_DiplomacyThreat_Details          ((k_Token_Custom_Base) + 3)
#define k_Token_DiplomacyThreat_Disabled         ((k_Token_Custom_Base) + 4)
#define k_Token_DiplomacyThreat_HasAlly          ((k_Token_Custom_Base) + 5)
#define k_Token_DiplomacyThreat_HasBorderIncursion ((k_Token_Custom_Base) + 6)
#define k_Token_DiplomacyThreat_IsPirating       ((k_Token_Custom_Base) + 7)
#define k_Token_DiplomacyThreat_HasEmbassy       ((k_Token_Custom_Base) + 8)
#define k_Token_DiplomacyThreat_HasHotwar        ((k_Token_Custom_Base) + 9)
#define k_Token_DiplomacyThreat_NoHotwar         ((k_Token_Custom_Base) + 10)
#define k_Token_DiplomacyThreat_HasPeaceTreaty   ((k_Token_Custom_Base) + 11)
#define k_Token_DiplomacyThreat_HasAlliance      ((k_Token_Custom_Base) + 12)
#define k_Token_DiplomacyThreat_HasNuclearWeapons ((k_Token_Custom_Base) + 13)
#define k_Token_DiplomacyThreat_HasBioWeapons    ((k_Token_Custom_Base) + 14)
#define k_Token_DiplomacyThreat_HasNanoWeapons   ((k_Token_Custom_Base) + 15)
#define k_Token_DiplomacyThreat_HasEmbargo       ((k_Token_Custom_Base) + 16)
#define k_Token_DiplomacyThreat_HasMilitaryAgreement ((k_Token_Custom_Base) + 17)
#define k_Token_DiplomacyThreat_HasPollutionAgreement ((k_Token_Custom_Base) + 18)
#define k_Token_DiplomacyThreat_HasPollution     ((k_Token_Custom_Base) + 19)
#define k_Token_DiplomacyThreat_Max              ((k_Token_Custom_Base) + 20)


static BitArray s_ParsedTokens(20);
void DiplomacyThreatRecord::CheckRequiredFields(DBLexer *lex)
{
    if(!s_ParsedTokens.Bit(k_Token_DiplomacyThreat_Title - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field Title missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_DiplomacyThreat_Type - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field Type missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_DiplomacyThreat_Details - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field Details missing"));
    }
}

sint32 DiplomacyThreatRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_DiplomacyThreat_Tokens, k_Token_DiplomacyThreat_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "DIPLOMACYTHREAT_%i", numRecords);
        if(!g_theStringDB->GetStringID(newName, m_name)) {
            g_theStringDB->InsertStr(newName, newName);
            if(!g_theStringDB->GetStringID(newName, m_name))
                SetTextName(newName);
        }
    }
    else{
        if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name)) {
            g_theStringDB->InsertStr(lex->GetTokenText(), lex->GetTokenText());
            if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name))
                SetTextName(lex->GetTokenText());
        }
        tok = lex->GetToken();
    }


    if(tok != k_Token_OpenBrace) {
        DBERROR(("Missing open brace"));
        return 0;
    }

    while(!done) {
        tok = lex->GetToken();
        if(tok >= k_Token_Custom_Base && tok < k_Token_DiplomacyThreat_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_DiplomacyThreat_Title:
                if(!lex->GetStringIdAssignment(m_Title)) {
                    DBERROR(("Expected string ID"));
                    done = true; break;
                }
                break;
            case k_Token_DiplomacyThreat_Type:
                if(!lex->GetFileAssignment(m_Type)) {
                    DBERROR(("Expected string"));
                    done = true; break;
                }
                break;
            case k_Token_DiplomacyThreat_Arg1:
                if(!ParseArg1Bit(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_DiplomacyThreat_Details:
                if(!lex->GetStringIdAssignment(m_Details)) {
                    DBERROR(("Expected string ID"));
                    done = true; break;
                }
                break;
            case k_Token_DiplomacyThreat_Disabled:
                m_flags0 |= k_DiplomacyThreat_Disabled_Bit;
                break;
            case k_Token_DiplomacyThreat_HasAlly:
                m_flags0 |= k_DiplomacyThreat_HasAlly_Bit;
                break;
            case k_Token_DiplomacyThreat_HasBorderIncursion:
                m_flags0 |= k_DiplomacyThreat_HasBorderIncursion_Bit;
                break;
            case k_Token_DiplomacyThreat_IsPirating:
                m_flags0 |= k_DiplomacyThreat_IsPirating_Bit;
                break;
            case k_Token_DiplomacyThreat_HasEmbassy:
                m_flags0 |= k_DiplomacyThreat_HasEmbassy_Bit;
                break;
            case k_Token_DiplomacyThreat_HasHotwar:
                m_flags0 |= k_DiplomacyThreat_HasHotwar_Bit;
                break;
            case k_Token_DiplomacyThreat_NoHotwar:
                m_flags0 |= k_DiplomacyThreat_NoHotwar_Bit;
                break;
            case k_Token_DiplomacyThreat_HasPeaceTreaty:
                m_flags0 |= k_DiplomacyThreat_HasPeaceTreaty_Bit;
                break;
            case k_Token_DiplomacyThreat_HasAlliance:
                m_flags0 |= k_DiplomacyThreat_HasAlliance_Bit;
                break;
            case k_Token_DiplomacyThreat_HasNuclearWeapons:
                m_flags0 |= k_DiplomacyThreat_HasNuclearWeapons_Bit;
                break;
            case k_Token_DiplomacyThreat_HasBioWeapons:
                m_flags0 |= k_DiplomacyThreat_HasBioWeapons_Bit;
                break;
            case k_Token_DiplomacyThreat_HasNanoWeapons:
                m_flags0 |= k_DiplomacyThreat_HasNanoWeapons_Bit;
                break;
            case k_Token_DiplomacyThreat_HasEmbargo:
                m_flags0 |= k_DiplomacyThreat_HasEmbargo_Bit;
                break;
            case k_Token_DiplomacyThreat_HasMilitaryAgreement:
                m_flags0 |= k_DiplomacyThreat_HasMilitaryAgreement_Bit;
                break;
            case k_Token_DiplomacyThreat_HasPollutionAgreement:
                m_flags0 |= k_DiplomacyThreat_HasPollutionAgreement_Bit;
                break;
            case k_Token_DiplomacyThreat_HasPollution:
                m_flags0 |= k_DiplomacyThreat_HasPollution_Bit;
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!lex->GetStringId(m_Title)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    CheckRequiredFields(lex);
    lex->RestoreTokens();
    return result;
}

void DiplomacyThreatRecord::ResolveDBReferences()
{
}

static const char *s_DiplomacyThreat_Arg1_BitNames[] = {
    "ThirdParty",
    "HisCity",
    "SpecialAttack",
    "AgreementId",
};
#define k_DiplomacyThreat_Arg1_Num_BitNames 4

sint32 DiplomacyThreatRecord::ParseArg1Bit(DBLexer *lex)
{
    sint32 bitindex;
    if(!lex->GetBitIndex((const char **)s_DiplomacyThreat_Arg1_BitNames, k_DiplomacyThreat_Arg1_Num_BitNames, bitindex)) {
        DBERROR(("%s is not a member of Arg1", lex->GetTokenText()));
        return 0;
    }
    m_Arg1 |= (1 << bitindex);
    return 1;
}

void DiplomacyThreatRecord::Merge(const DiplomacyThreatRecord & rval){
    // only replace values that have been set
    if (rval.m_Arg1)
    {
        m_Arg1 = rval.m_Arg1;
    }

}

