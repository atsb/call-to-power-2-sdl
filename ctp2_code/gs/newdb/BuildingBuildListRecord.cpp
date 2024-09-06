
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "BuildingBuildListRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "BuildingRecord.h"

CTPDatabase<BuildingBuildListRecord> *g_theBuildingBuildListDB = NULL;

void BuildingBuildListRecord::Init()
{
    m_Building = NULL;
    m_numBuilding = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void BuildingBuildListRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_numBuilding;
        archive.Store((uint8*)m_Building, m_numBuilding * sizeof(sint32));

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
        archive >> m_numBuilding;
        archive.Load((uint8*)m_Building, m_numBuilding * sizeof(sint32));

    }
}

BuildingBuildListRecord::~BuildingBuildListRecord()
{
    delete [] m_Building;
}

BuildingBuildListRecord const & BuildingBuildListRecord::operator = (BuildingBuildListRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_Building;
        m_Building = NULL;
        if (rval.m_numBuilding > 0)
        {
            m_Building = new sint32 [rval.m_numBuilding];
            std::copy(rval.m_Building, rval.m_Building + rval.m_numBuilding, m_Building);
        }
        m_numBuilding = rval.m_numBuilding;

    }

    return *this;
}

const char *g_BuildingBuildList_Tokens[] =
{
    "Building",
};

BuildingBuildListRecordAccessorInfo g_BuildingBuildListRecord_Accessors[] =
{
    { &BuildingBuildListRecord::GetNumBuilding, NULL, NULL, NULL, NULL, &BuildingBuildListRecord::GetBuildingIndex, NULL}, /* Building (array) */
};

#define k_Token_BuildingBuildList_Building       ((k_Token_Custom_Base) + 0)
#define k_Token_BuildingBuildList_Max            ((k_Token_Custom_Base) + 1)


static BitArray s_ParsedTokens(1);
void BuildingBuildListRecord::CheckRequiredFields(DBLexer *lex)
{
}

sint32 BuildingBuildListRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_BuildingBuildList_Tokens, k_Token_BuildingBuildList_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "BUILDINGBUILDLIST_%i", numRecords);
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
        if(tok >= k_Token_Custom_Base && tok < k_Token_BuildingBuildList_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_BuildingBuildList_Building:
                if(!g_theBuildingDB->ParseRecordInArray(lex, (sint32 **)&m_Building, &m_numBuilding))
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
                if(!g_theBuildingDB->ParseRecordInArray(lex, &m_Building, &m_numBuilding)) {
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

void BuildingBuildListRecord::ResolveDBReferences()
{
    {
        sint32 i;
        for(i = 0; i < m_numBuilding; i++) {
            if(m_Building[i] & 0x80000000) {
                sint32 id = m_Building[i] & 0x7fffffff;
                if(!g_theBuildingDB->GetNamedItem(id, m_Building[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in Building database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_Building[i] == 0x7fffffff){
                m_Building[i] = -1;
            }
        }
    }
}

void BuildingBuildListRecord::Merge(const BuildingBuildListRecord & rval){
    // resize m_Building if necessary
    if (rval.m_numBuilding > m_numBuilding)
    {
        delete [] m_Building;
        m_Building = NULL;
        if (rval.m_numBuilding > 0)
            m_Building = new sint32 [rval.m_numBuilding];
        m_numBuilding = rval.m_numBuilding;
    }
    if (rval.m_numBuilding > 0)
        std::copy(rval.m_Building, rval.m_Building + rval.m_numBuilding, m_Building);

}

sint32 BuildingBuildListRecord::GetBuildingIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numBuilding);
    if((index < 0) || (index >= m_numBuilding)) {
        return 0;
    }
    return m_Building[index];
}

BuildingRecord const * BuildingBuildListRecord::GetBuilding(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numBuilding);
    if((index < 0) || (index >= m_numBuilding)) {
        return 0;
    }
    return g_theBuildingDB->Get(m_Building[index]);
}

