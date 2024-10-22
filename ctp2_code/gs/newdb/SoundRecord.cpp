
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "SoundRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"


CTPDatabase<SoundRecord> *g_theSoundDB = NULL;

void SoundRecord::Init()
{
    m_Value = NULL;
    m_NameText = NULL;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void SoundRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_Value;
        archive << m_NameText;
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
        m_Value = NULL;
        archive >> m_Value;

        m_NameText = NULL;
        archive >> m_NameText;

    }
}

SoundRecord::~SoundRecord()
{
    delete m_Value;
    delete m_NameText;
}

SoundRecord const & SoundRecord::operator = (SoundRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_Value;
        m_Value = NULL;

        if (rval.m_Value)
        {
            m_Value = new char [strlen(rval.m_Value)+1];
            strcpy(m_Value, rval.m_Value);
        }

        delete [] m_NameText;
        m_NameText = NULL;

        if (rval.m_NameText)
        {
            m_NameText = new char [strlen(rval.m_NameText)+1];
            strcpy(m_NameText, rval.m_NameText);
        }

    }

    return *this;
}

const char *g_Sound_Tokens[] =
{
    "Value",
    "NameText",
};

SoundRecordAccessorInfo g_SoundRecord_Accessors[] =
{
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* Value */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* NameText */
};

#define k_Token_Sound_Value                      ((k_Token_Custom_Base) + 0)
#define k_Token_Sound_NameText                   ((k_Token_Custom_Base) + 1)
#define k_Token_Sound_Max                        ((k_Token_Custom_Base) + 2)


static BitArray s_ParsedTokens(2);
void SoundRecord::CheckRequiredFields(DBLexer *lex)
{
    if(!s_ParsedTokens.Bit(k_Token_Sound_Value - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field Value missing"));
    }
}

sint32 SoundRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    sint32 tok;
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        DBERROR(("Record must start with name"));
        return 0;
    }
    m_NameText = new char[strlen(lex->GetTokenText()) + 1];
    strcpy(m_NameText, lex->GetTokenText());
    if(!lex->GetFileAssignment(m_Value)) {
        DBERROR(("Expected string"));
        return 0;
    }
    return 1;
}
void SoundRecord::ResolveDBReferences()
{
}

void SoundRecord::Merge(const SoundRecord & rval){
}

