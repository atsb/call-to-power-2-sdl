
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "AdvanceListRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "AdvanceRecord.h"

CTPDatabase<AdvanceListRecord> *g_theAdvanceListDB = NULL;

void AdvanceListRecord::Init()
{
    m_Advance = NULL;
    m_numAdvance = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void AdvanceListRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_numAdvance;
        archive.Store((uint8*)m_Advance, m_numAdvance * sizeof(sint32));

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
        archive >> m_numAdvance;
        archive.Load((uint8*)m_Advance, m_numAdvance * sizeof(sint32));

    }
}

AdvanceListRecord::~AdvanceListRecord()
{
    delete [] m_Advance;
}

AdvanceListRecord const & AdvanceListRecord::operator = (AdvanceListRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_Advance;
        m_Advance = NULL;
        if (rval.m_numAdvance > 0)
        {
            m_Advance = new sint32 [rval.m_numAdvance];
            std::copy(rval.m_Advance, rval.m_Advance + rval.m_numAdvance, m_Advance);
        }
        m_numAdvance = rval.m_numAdvance;

    }

    return *this;
}

const char *g_AdvanceList_Tokens[] =
{
    "Advance",
};

AdvanceListRecordAccessorInfo g_AdvanceListRecord_Accessors[] =
{
    { &AdvanceListRecord::GetNumAdvance, NULL, NULL, NULL, NULL, &AdvanceListRecord::GetAdvanceIndex, NULL}, /* Advance (array) */
};

#define k_Token_AdvanceList_Advance              ((k_Token_Custom_Base) + 0)
#define k_Token_AdvanceList_Max                  ((k_Token_Custom_Base) + 1)


static BitArray s_ParsedTokens(1);
void AdvanceListRecord::CheckRequiredFields(DBLexer *lex)
{
}

sint32 AdvanceListRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_AdvanceList_Tokens, k_Token_AdvanceList_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "ADVANCELIST_%i", numRecords);
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
        if(tok >= k_Token_Custom_Base && tok < k_Token_AdvanceList_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_AdvanceList_Advance:
                if(!g_theAdvanceDB->ParseRecordInArray(lex, (sint32 **)&m_Advance, &m_numAdvance))
                {
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                Assert(false)
                if(!g_theAdvanceDB->ParseRecordInArray(lex, &m_Advance, &m_numAdvance)) {
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

void AdvanceListRecord::ResolveDBReferences()
{
    {
        sint32 i;
        for(i = 0; i < m_numAdvance; i++) {
            if(m_Advance[i] & 0x80000000) {
                sint32 id = m_Advance[i] & 0x7fffffff;
                if(!g_theAdvanceDB->GetNamedItem(id, m_Advance[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in Advance database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_Advance[i] == 0x7fffffff){
                m_Advance[i] = -1;
            }
        }
    }
}

void AdvanceListRecord::Merge(const AdvanceListRecord & rval){
    // resize m_Advance if necessary
    if (rval.m_numAdvance > m_numAdvance)
    {
        delete [] m_Advance;
        m_Advance = NULL;
        if (rval.m_numAdvance > 0)
            m_Advance = new sint32 [rval.m_numAdvance];
        m_numAdvance = rval.m_numAdvance;
    }
    if (rval.m_numAdvance > 0)
        std::copy(rval.m_Advance, rval.m_Advance + rval.m_numAdvance, m_Advance);

}

sint32 AdvanceListRecord::GetAdvanceIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numAdvance);
    if((index < 0) || (index >= m_numAdvance)) {
        return 0;
    }
    return m_Advance[index];
}

AdvanceRecord const * AdvanceListRecord::GetAdvance(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numAdvance);
    if((index < 0) || (index >= m_numAdvance)) {
        return 0;
    }
    return g_theAdvanceDB->Get(m_Advance[index]);
}

