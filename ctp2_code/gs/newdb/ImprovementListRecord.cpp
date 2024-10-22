
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "ImprovementListRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "TerrainImprovementRecord.h"

CTPDatabase<ImprovementListRecord> *g_theImprovementListDB = NULL;

void ImprovementListRecord::Init()
{
    m_Improvement = NULL;
    m_numImprovement = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void ImprovementListRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_numImprovement;
        archive.Store((uint8*)m_Improvement, m_numImprovement * sizeof(sint32));

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
        archive >> m_numImprovement;
        archive.Load((uint8*)m_Improvement, m_numImprovement * sizeof(sint32));

    }
}

ImprovementListRecord::~ImprovementListRecord()
{
    delete [] m_Improvement;
}

ImprovementListRecord const & ImprovementListRecord::operator = (ImprovementListRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_Improvement;
        m_Improvement = NULL;
        if (rval.m_numImprovement > 0)
        {
            m_Improvement = new sint32 [rval.m_numImprovement];
            std::copy(rval.m_Improvement, rval.m_Improvement + rval.m_numImprovement, m_Improvement);
        }
        m_numImprovement = rval.m_numImprovement;

    }

    return *this;
}

const char *g_ImprovementList_Tokens[] =
{
    "Improvement",
};

ImprovementListRecordAccessorInfo g_ImprovementListRecord_Accessors[] =
{
    { &ImprovementListRecord::GetNumImprovement, NULL, NULL, NULL, NULL, &ImprovementListRecord::GetImprovementIndex, NULL}, /* Improvement (array) */
};

#define k_Token_ImprovementList_Improvement      ((k_Token_Custom_Base) + 0)
#define k_Token_ImprovementList_Max              ((k_Token_Custom_Base) + 1)


static BitArray s_ParsedTokens(1);
void ImprovementListRecord::CheckRequiredFields(DBLexer *lex)
{
}

sint32 ImprovementListRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_ImprovementList_Tokens, k_Token_ImprovementList_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "IMPROVEMENTLIST_%i", numRecords);
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
        if(tok >= k_Token_Custom_Base && tok < k_Token_ImprovementList_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_ImprovementList_Improvement:
                if(!g_theTerrainImprovementDB->ParseRecordInArray(lex, (sint32 **)&m_Improvement, &m_numImprovement))
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
                if(!g_theTerrainImprovementDB->ParseRecordInArray(lex, &m_Improvement, &m_numImprovement)) {
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

void ImprovementListRecord::ResolveDBReferences()
{
    {
        sint32 i;
        for(i = 0; i < m_numImprovement; i++) {
            if(m_Improvement[i] & 0x80000000) {
                sint32 id = m_Improvement[i] & 0x7fffffff;
                if(!g_theTerrainImprovementDB->GetNamedItem(id, m_Improvement[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in TerrainImprovement database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_Improvement[i] == 0x7fffffff){
                m_Improvement[i] = -1;
            }
        }
    }
}

void ImprovementListRecord::Merge(const ImprovementListRecord & rval){
    // resize m_Improvement if necessary
    if (rval.m_numImprovement > m_numImprovement)
    {
        delete [] m_Improvement;
        m_Improvement = NULL;
        if (rval.m_numImprovement > 0)
            m_Improvement = new sint32 [rval.m_numImprovement];
        m_numImprovement = rval.m_numImprovement;
    }
    if (rval.m_numImprovement > 0)
        std::copy(rval.m_Improvement, rval.m_Improvement + rval.m_numImprovement, m_Improvement);

}

sint32 ImprovementListRecord::GetImprovementIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numImprovement);
    if((index < 0) || (index >= m_numImprovement)) {
        return 0;
    }
    return m_Improvement[index];
}

TerrainImprovementRecord const * ImprovementListRecord::GetImprovement(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numImprovement);
    if((index < 0) || (index >= m_numImprovement)) {
        return 0;
    }
    return g_theTerrainImprovementDB->Get(m_Improvement[index]);
}

