
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "TerrainRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "IconRecord.h"
#include "AdvanceRecord.h"
#include "AdvanceRecord.h"
#include "ResourceRecord.h"

CTPDatabase<TerrainRecord> *g_theTerrainDB = NULL;

void TerrainRecord::Init()
{
    m_flags0 = 0;
    m_Icon = 0x7fffffff;
    m_AddAdvance = 0x7fffffff;
    m_RemoveAdvance = 0x7fffffff;
    memset(&m_TransformAddValue, 0, sizeof(m_TransformAddValue));
    memset(&m_TransformRemoveValue, 0, sizeof(m_TransformRemoveValue));
    memset((uint8*)&m_EnvBase, 0, sizeof(m_EnvBase));
    memset(&m_EnvCityValue, 0, sizeof(m_EnvCityValue));
    memset(&m_EnvRiverValue, 0, sizeof(m_EnvRiverValue));
    m_HostileTerrainCostValue = 0;
    memset(m_Resources, 0, sizeof(m_Resources));
    m_numResources = 0;
    m_MovementType = 0;
    m_InternalType = 0;
    m_TilesetIndex = 0;
    m_HutTilesetIndexA = 150;
    m_HutTilesetIndexB = 151;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void TerrainRecord::Serialize(CivArchive &archive)
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
        archive << m_Icon;
        archive << m_AddAdvance;
        archive << m_RemoveAdvance;
        m_TransformAddValue.Serialize(archive);
        m_TransformRemoveValue.Serialize(archive);
        m_EnvBase.Serialize(archive);
        m_EnvCityValue.Serialize(archive);
        m_EnvRiverValue.Serialize(archive);
        archive << m_HostileTerrainCostValue;
        archive << m_numResources;
        archive.Store((uint8*)&m_Resources, sizeof(m_Resources));
        archive << m_MovementType;
        archive << m_InternalType;
        archive << m_TilesetIndex;
        archive << m_HutTilesetIndexA;
        archive << m_HutTilesetIndexB;
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
        archive >> m_Icon;
        archive >> m_AddAdvance;
        archive >> m_RemoveAdvance;
        memset((uint8*)&m_TransformAddValue, 0, sizeof(m_TransformAddValue));
        m_TransformAddValue.Serialize(archive);
        memset((uint8*)&m_TransformRemoveValue, 0, sizeof(m_TransformRemoveValue));
        m_TransformRemoveValue.Serialize(archive);
        memset((uint8*)&m_EnvBase, 0, sizeof(m_EnvBase));
        m_EnvBase.Serialize(archive);
        memset((uint8*)&m_EnvCityValue, 0, sizeof(m_EnvCityValue));
        m_EnvCityValue.Serialize(archive);
        memset((uint8*)&m_EnvRiverValue, 0, sizeof(m_EnvRiverValue));
        m_EnvRiverValue.Serialize(archive);
        archive >> m_HostileTerrainCostValue;
        archive >> m_numResources;
        archive.Load((uint8*)&m_Resources, sizeof(m_Resources));
        archive >> m_MovementType;
        archive >> m_InternalType;
        archive >> m_TilesetIndex;
        archive >> m_HutTilesetIndexA;
        archive >> m_HutTilesetIndexB;
    }
}

TerrainRecord::~TerrainRecord()
{
}

TerrainRecord const & TerrainRecord::operator = (TerrainRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_flags0 = rval.m_flags0;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        m_Icon = rval.m_Icon;

        m_AddAdvance = rval.m_AddAdvance;

        m_RemoveAdvance = rval.m_RemoveAdvance;

        m_TransformAddValue = rval.m_TransformAddValue;

        m_TransformRemoveValue = rval.m_TransformRemoveValue;

        m_EnvBase = rval.m_EnvBase;

        m_EnvCityValue = rval.m_EnvCityValue;

        m_EnvRiverValue = rval.m_EnvRiverValue;

        m_HostileTerrainCostValue = rval.m_HostileTerrainCostValue;

        std::copy(rval.m_Resources, rval.m_Resources + rval.m_numResources, m_Resources);

        m_MovementType = rval.m_MovementType;

        m_InternalType = rval.m_InternalType;

        m_TilesetIndex = rval.m_TilesetIndex;

        m_HutTilesetIndexA = rval.m_HutTilesetIndexA;

        m_HutTilesetIndexB = rval.m_HutTilesetIndexB;

    }

    return *this;
}

const char *g_Terrain_Tokens[] =
{
    "Icon",
    "AddAdvance",
    "RemoveAdvance",
    "CanDie",
    "GLHidden",
    "TransformAdd",
    "TransformAddValue",
    "TransformRemove",
    "TransformRemoveValue",
    "EnvBase",
    "EnvCity",
    "EnvCityValue",
    "EnvRiver",
    "EnvRiverValue",
    "HostileTerrainCost",
    "HostileTerrainCostValue",
    "Resources",
    "NoIndex",
    "MovementType",
    "InternalType",
    "TilesetIndex",
    "HutTilesetIndexA",
    "HutTilesetIndexB",
};

TerrainRecordAccessorInfo g_TerrainRecord_Accessors[] =
{
    { &TerrainRecord::GetIconIndex, NULL, NULL, NULL, NULL, NULL, NULL },
    { &TerrainRecord::GetAddAdvanceIndex, NULL, NULL, NULL, NULL, NULL, NULL },
    { &TerrainRecord::GetRemoveAdvanceIndex, NULL, NULL, NULL, NULL, NULL, NULL },
    { NULL, &TerrainRecord::GetCanDie, NULL, NULL, NULL, NULL, NULL },
    { NULL, &TerrainRecord::GetGLHidden, NULL, NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* TransformAdd */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* TransformAdd */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* TransformRemove */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* TransformRemove */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* EnvBase */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* EnvCity */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* EnvCity */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* EnvRiver */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* EnvRiver */
    { NULL, NULL, NULL, &TerrainRecord::GetHostileTerrainCost, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* HostileTerrainCost */
    { &TerrainRecord::GetNumResources, NULL, NULL, NULL, NULL, &TerrainRecord::GetResourcesIndex, NULL}, /* Resources (array) */
    { NULL, &TerrainRecord::GetNoIndex, NULL, NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* MovementType */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* InternalType */
    { &TerrainRecord::GetTilesetIndex, NULL, NULL, NULL, NULL, NULL, NULL },
    { &TerrainRecord::GetHutTilesetIndexA, NULL, NULL, NULL, NULL, NULL, NULL },
    { &TerrainRecord::GetHutTilesetIndexB, NULL, NULL, NULL, NULL, NULL, NULL },
};

#define k_Token_Terrain_Icon                     ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_AddAdvance               ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_RemoveAdvance            ((k_Token_Custom_Base) + 2)
#define k_Token_Terrain_CanDie                   ((k_Token_Custom_Base) + 3)
#define k_Token_Terrain_GLHidden                 ((k_Token_Custom_Base) + 4)
#define k_Token_Terrain_TransformAdd             ((k_Token_Custom_Base) + 5)
#define k_Token_Terrain_TransformAdd_Value       ((k_Token_Custom_Base) + 6)
#define k_Token_Terrain_TransformRemove          ((k_Token_Custom_Base) + 7)
#define k_Token_Terrain_TransformRemove_Value    ((k_Token_Custom_Base) + 8)
#define k_Token_Terrain_EnvBase                  ((k_Token_Custom_Base) + 9)
#define k_Token_Terrain_EnvCity                  ((k_Token_Custom_Base) + 10)
#define k_Token_Terrain_EnvCity_Value            ((k_Token_Custom_Base) + 11)
#define k_Token_Terrain_EnvRiver                 ((k_Token_Custom_Base) + 12)
#define k_Token_Terrain_EnvRiver_Value           ((k_Token_Custom_Base) + 13)
#define k_Token_Terrain_HostileTerrainCost       ((k_Token_Custom_Base) + 14)
#define k_Token_Terrain_HostileTerrainCost_Value ((k_Token_Custom_Base) + 15)
#define k_Token_Terrain_Resources                ((k_Token_Custom_Base) + 16)
#define k_Token_Terrain_NoIndex                  ((k_Token_Custom_Base) + 17)
#define k_Token_Terrain_MovementType             ((k_Token_Custom_Base) + 18)
#define k_Token_Terrain_InternalType             ((k_Token_Custom_Base) + 19)
#define k_Token_Terrain_TilesetIndex             ((k_Token_Custom_Base) + 20)
#define k_Token_Terrain_HutTilesetIndexA         ((k_Token_Custom_Base) + 21)
#define k_Token_Terrain_HutTilesetIndexB         ((k_Token_Custom_Base) + 22)
#define k_Token_Terrain_Max                      ((k_Token_Custom_Base) + 23)


static BitArray s_ParsedTokens(23);
void TerrainRecord::CheckRequiredFields(DBLexer *lex)
{
    if(!s_ParsedTokens.Bit(k_Token_Terrain_EnvBase - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field EnvBase missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_Terrain_TilesetIndex - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field TilesetIndex missing"));
    }
}

sint32 TerrainRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_Terrain_Tokens, k_Token_Terrain_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "TERRAIN_%i", numRecords);
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
        if(tok >= k_Token_Custom_Base && tok < k_Token_Terrain_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_Terrain_Icon:
                if (!g_theIconDB->GetRecordFromLexer(lex, m_Icon)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_AddAdvance:
                if (!g_theAdvanceDB->GetRecordFromLexer(lex, m_AddAdvance)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_RemoveAdvance:
                if (!g_theAdvanceDB->GetRecordFromLexer(lex, m_RemoveAdvance)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_CanDie:
                m_flags0 |= k_Terrain_CanDie_Bit;
                break;
            case k_Token_Terrain_GLHidden:
                m_flags0 |= k_Terrain_GLHidden_Bit;
                break;
            case k_Token_Terrain_TransformAdd:
                m_flags0 |= k_Terrain_TransformAdd_Bit;
                if(!m_TransformAddValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TransformRemove:
                m_flags0 |= k_Terrain_TransformRemove_Bit;
                if(!m_TransformRemoveValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvBase:
                if(!m_EnvBase.Parse(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvCity:
                m_flags0 |= k_Terrain_EnvCity_Bit;
                if(!m_EnvCityValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvRiver:
                m_flags0 |= k_Terrain_EnvRiver_Bit;
                if(!m_EnvRiverValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_HostileTerrainCost:
                m_flags0 |= k_Terrain_HostileTerrainCost_Bit;
                if(!lex->GetIntAssignment(m_HostileTerrainCostValue)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Resources:
                if(!g_theResourceDB->ParseRecordInArray(lex, (sint32 *)m_Resources, &m_numResources, k_MAX_Resources)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_NoIndex:
                m_flags0 |= k_Terrain_NoIndex_Bit;
                break;
            case k_Token_Terrain_MovementType:
                if(!ParseMovementTypeBit(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_InternalType:
                if(!ParseInternalTypeBit(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TilesetIndex:
                if(!lex->GetIntAssignment(m_TilesetIndex)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_HutTilesetIndexA:
                if(!lex->GetIntAssignment(m_HutTilesetIndexA)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_HutTilesetIndexB:
                if(!lex->GetIntAssignment(m_HutTilesetIndexB)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!g_theIconDB->GetCurrentRecordFromLexer(lex, m_Icon)) {
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

void TerrainRecord::ResolveDBReferences()
{
    if(m_Icon & 0x80000000) {
        sint32 id = m_Icon & 0x7fffffff;
        if(!g_theIconDB->GetNamedItem(id, m_Icon)) {
            c3errors_ErrorDialog("DB", "%s not found in Icon database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_Icon == 0x7fffffff) {
        m_Icon = -1;
    }
    if(m_AddAdvance & 0x80000000) {
        sint32 id = m_AddAdvance & 0x7fffffff;
        if(!g_theAdvanceDB->GetNamedItem(id, m_AddAdvance)) {
            c3errors_ErrorDialog("DB", "%s not found in Advance database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_AddAdvance == 0x7fffffff) {
        m_AddAdvance = -1;
    }
    if(m_RemoveAdvance & 0x80000000) {
        sint32 id = m_RemoveAdvance & 0x7fffffff;
        if(!g_theAdvanceDB->GetNamedItem(id, m_RemoveAdvance)) {
            c3errors_ErrorDialog("DB", "%s not found in Advance database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_RemoveAdvance == 0x7fffffff) {
        m_RemoveAdvance = -1;
    }
    m_TransformAddValue.ResolveDBReferences();
    m_TransformRemoveValue.ResolveDBReferences();
    m_EnvBase.ResolveDBReferences();
    m_EnvCityValue.ResolveDBReferences();
    m_EnvRiverValue.ResolveDBReferences();
    {
        sint32 i;
        for(i = 0; i < m_numResources; i++) {
            if(m_Resources[i] & 0x80000000) {
                sint32 id = m_Resources[i] & 0x7fffffff;
                if(!g_theResourceDB->GetNamedItem(id, m_Resources[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in Resource database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_Resources[i] == 0x7fffffff){
                m_Resources[i] = -1;
            }
        }
    }
}

TerrainRecord::TransformData::TransformData()
{
    m_Time = 0;
    m_Materials = 0;
}

TerrainRecord::TransformData::~TransformData()
{
}

TerrainRecord::TransformData const & TerrainRecord::TransformData::operator = (TransformData const & rval)
{
    if (this != &rval)
    {

        m_Time = rval.m_Time;

        m_Materials = rval.m_Materials;

    }

    return *this;
}

void TerrainRecord::TransformData::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_Time;
        archive << m_Materials;
    } else {
        archive >> m_Time;
        archive >> m_Materials;
    }
}

static const char *s_Terrain_TransformData_Tokens[] = {
    "Time",
    "Materials",
};
#define k_Token_Terrain_TransformData_Time       ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_TransformData_Materials  ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_TransformData_Max ((k_Token_Custom_Base) + 2)
sint32 TerrainRecord::TransformData::ParseSequential(DBLexer *lex)
{
    if(!lex->GetIntAssignment(m_Time)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    if(!lex->GetIntAssignment(m_Materials)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    return 1;
}

sint32 TerrainRecord::TransformData::ParseFullySequential(DBLexer *lex)
{
    if(!lex->GetInt(m_Time)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    lex->GetToken();
    if(!lex->GetInt(m_Materials)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    return 1;
}

sint32 TerrainRecord::TransformData::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    sint32 result = 0;
    tok = lex->PeekAhead();
    if(tok != k_Token_OpenBrace) {
        if(lex->GetCurrentToken() != k_Token_OpenBrace) {
            if(ParseSequential(lex)) {
                return 1;
            }
            DBERROR(("Expected open brace for TransformData"));
            return 0;
        }
    }
    else {
        tok = lex->GetToken();
    }
    lex->SetTokens(s_Terrain_TransformData_Tokens, k_Token_Terrain_TransformData_Max);
    while(!done) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_Terrain_TransformData_Time:
                if(!lex->GetIntAssignment(m_Time)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TransformData_Materials:
                if(!lex->GetIntAssignment(m_Materials)) {
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!lex->GetInt(m_Time)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    lex->RestoreTokens();
    return result;
}

sint32 TerrainRecord::TransformData::ParseInArray(DBLexer *lex, TransformData **array, sint32 *numElements)
{
    if(*numElements > 0) {
        TransformData *oldArray = *array;
        *array = new TransformData[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++)
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new TransformData[1];
    }
    (*array)[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

sint32 TerrainRecord::TransformData::ParseInArray(DBLexer *lex, TransformData *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

sint32 TerrainRecord::TransformData::ParseInArraySequential(DBLexer *lex, TransformData **array, sint32 *numElements)
{
    if(*numElements > 0) {
        TransformData *oldArray = *array;
        *array = new TransformData[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++)
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new TransformData[1];
    }
    (*array)[*numElements].ParseFullySequential(lex);
    *numElements += 1;
    return 1;
}

sint32 TerrainRecord::TransformData::ParseInArraySequential(DBLexer *lex, TransformData *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].ParseFullySequential(lex);
    *numElements += 1;
    return 1;
}

void TerrainRecord::TransformData::ResolveDBReferences()
{
}

TerrainRecord::Modifiers::Modifiers()
{
    m_flags0 = 0;
    m_Score = 0;
    m_Gold = 0;
    m_DeadGold = 0;
    m_Food = 0;
    m_Shield = 0;
    m_MovementValue = 0;
    m_Freight = 0;
    m_Materials = 0;
    m_Time = 0;
    m_Defense = 0.000000;
    m_DeadFood = 0;
    m_DeadShield = 0;
}

TerrainRecord::Modifiers::~Modifiers()
{
}

TerrainRecord::Modifiers const & TerrainRecord::Modifiers::operator = (Modifiers const & rval)
{
    if (this != &rval)
    {
        m_flags0 = rval.m_flags0;

        m_Score = rval.m_Score;

        m_Gold = rval.m_Gold;

        m_DeadGold = rval.m_DeadGold;

        m_Food = rval.m_Food;

        m_Shield = rval.m_Shield;

        m_MovementValue = rval.m_MovementValue;

        m_Freight = rval.m_Freight;

        m_Materials = rval.m_Materials;

        m_Time = rval.m_Time;

        m_Defense = rval.m_Defense;

        m_DeadFood = rval.m_DeadFood;

        m_DeadShield = rval.m_DeadShield;

    }

    return *this;
}

void TerrainRecord::Modifiers::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_flags0;
        archive << m_Score;
        archive << m_Gold;
        archive << m_DeadGold;
        archive << m_Food;
        archive << m_Shield;
        archive << m_MovementValue;
        archive << m_Freight;
        archive << m_Materials;
        archive << m_Time;
        archive << m_Defense;
        archive << m_DeadFood;
        archive << m_DeadShield;
    } else {
        archive >> m_flags0;
        archive >> m_Score;
        archive >> m_Gold;
        archive >> m_DeadGold;
        archive >> m_Food;
        archive >> m_Shield;
        archive >> m_MovementValue;
        archive >> m_Freight;
        archive >> m_Materials;
        archive >> m_Time;
        archive >> m_Defense;
        archive >> m_DeadFood;
        archive >> m_DeadShield;
    }
}

static const char *s_Terrain_Modifiers_Tokens[] = {
    "Score",
    "Gold",
    "DeadGold",
    "Food",
    "Shield",
    "Movement",
    "Freight",
    "Materials",
    "Time",
    "Defense",
    "DeadFood",
    "DeadShield",
    "CanUpgrade",
};
#define k_Token_Terrain_Modifiers_Score          ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_Modifiers_Gold           ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_Modifiers_DeadGold       ((k_Token_Custom_Base) + 2)
#define k_Token_Terrain_Modifiers_Food           ((k_Token_Custom_Base) + 3)
#define k_Token_Terrain_Modifiers_Shield         ((k_Token_Custom_Base) + 4)
#define k_Token_Terrain_Modifiers_Movement       ((k_Token_Custom_Base) + 5)
#define k_Token_Terrain_Modifiers_Freight        ((k_Token_Custom_Base) + 6)
#define k_Token_Terrain_Modifiers_Materials      ((k_Token_Custom_Base) + 7)
#define k_Token_Terrain_Modifiers_Time           ((k_Token_Custom_Base) + 8)
#define k_Token_Terrain_Modifiers_Defense        ((k_Token_Custom_Base) + 9)
#define k_Token_Terrain_Modifiers_DeadFood       ((k_Token_Custom_Base) + 10)
#define k_Token_Terrain_Modifiers_DeadShield     ((k_Token_Custom_Base) + 11)
#define k_Token_Terrain_Modifiers_CanUpgrade     ((k_Token_Custom_Base) + 12)
#define k_Token_Terrain_Modifiers_Max ((k_Token_Custom_Base) + 13)
sint32 TerrainRecord::Modifiers::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    sint32 result = 0;
    tok = lex->PeekAhead();
    if(tok != k_Token_OpenBrace) {
        if(lex->GetCurrentToken() != k_Token_OpenBrace) {
            DBERROR(("Expected open brace for Modifiers"));
            return 0;
        }
    }
    else {
        tok = lex->GetToken();
    }
    lex->SetTokens(s_Terrain_Modifiers_Tokens, k_Token_Terrain_Modifiers_Max);
    while(!done) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_Terrain_Modifiers_Score:
                if(!lex->GetIntAssignment(m_Score)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Gold:
                if(!lex->GetIntAssignment(m_Gold)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadGold:
                if(!lex->GetIntAssignment(m_DeadGold)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Food:
                if(!lex->GetIntAssignment(m_Food)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Shield:
                if(!lex->GetIntAssignment(m_Shield)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Movement:
                m_flags0 |= k_Modifiers_Movement_Bit;
                if(!lex->GetIntAssignment(m_MovementValue)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Freight:
                if(!lex->GetIntAssignment(m_Freight)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Materials:
                if(!lex->GetIntAssignment(m_Materials)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Time:
                if(!lex->GetIntAssignment(m_Time)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Defense:
                if(!lex->GetFloatAssignment(m_Defense)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadFood:
                if(!lex->GetIntAssignment(m_DeadFood)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadShield:
                if(!lex->GetIntAssignment(m_DeadShield)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_CanUpgrade:
                m_flags0 |= k_Modifiers_CanUpgrade_Bit;
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!lex->GetInt(m_Score)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    lex->RestoreTokens();
    return result;
}

sint32 TerrainRecord::Modifiers::ParseInArray(DBLexer *lex, Modifiers **array, sint32 *numElements)
{
    if(*numElements > 0) {
        Modifiers *oldArray = *array;
        *array = new Modifiers[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++)
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new Modifiers[1];
    }
    (*array)[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

sint32 TerrainRecord::Modifiers::ParseInArray(DBLexer *lex, Modifiers *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

void TerrainRecord::Modifiers::ResolveDBReferences()
{
}

static const char *s_Terrain_MovementType_BitNames[] = {
    "Land",
    "Sea",
    "Air",
    "Mountain",
    "Trade",
    "ShallowWater",
    "Space",
};
#define k_Terrain_MovementType_Num_BitNames 7

sint32 TerrainRecord::ParseMovementTypeBit(DBLexer *lex)
{
    sint32 bitindex;
    if(!lex->GetBitIndex((const char **)s_Terrain_MovementType_BitNames, k_Terrain_MovementType_Num_BitNames, bitindex)) {
        DBERROR(("%s is not a member of MovementType", lex->GetTokenText()));
        return 0;
    }
    m_MovementType |= (1 << bitindex);
    return 1;
}

static const char *s_Terrain_InternalType_BitNames[] = {
    "Forest",
    "Plains",
    "Tundra",
    "Glacier",
    "Grassland",
    "Desert",
    "Swamp",
    "Jungle",
    "Mountain",
    "Hill",
    "WaterShallow",
    "WaterDeep",
    "WaterVolcano",
    "WaterBeach",
    "WaterShelf",
    "WaterTrench",
    "WaterRift",
    "Dead",
    "BrownHill",
    "BrownMountain",
    "WhiteHill",
    "WhiteMountain",
    "WaterKelp",
    "WaterReef",
    "Special",
};
#define k_Terrain_InternalType_Num_BitNames 25

sint32 TerrainRecord::ParseInternalTypeBit(DBLexer *lex)
{
    sint32 bitindex;
    if(!lex->GetBitIndex((const char **)s_Terrain_InternalType_BitNames, k_Terrain_InternalType_Num_BitNames, bitindex)) {
        DBERROR(("%s is not a member of InternalType", lex->GetTokenText()));
        return 0;
    }
    m_InternalType |= (1 << bitindex);
    return 1;
}

void TerrainRecord::Merge(const TerrainRecord & rval){
    // only replace values that have been set
    if (rval.m_flags0 & k_Terrain_TransformAdd_Bit)
    {
        m_TransformAddValue = rval.m_TransformAddValue;
    }

    // only replace values that have been set
    if (rval.m_flags0 & k_Terrain_TransformRemove_Bit)
    {
        m_TransformRemoveValue = rval.m_TransformRemoveValue;
    }

    // only replace values that have been set
    if (rval.m_flags0 & k_Terrain_EnvCity_Bit)
    {
        m_EnvCityValue = rval.m_EnvCityValue;
    }

    // only replace values that have been set
    if (rval.m_flags0 & k_Terrain_EnvRiver_Bit)
    {
        m_EnvRiverValue = rval.m_EnvRiverValue;
    }

    // only replace values that have been set
    if (rval.m_flags0 & k_Terrain_HostileTerrainCost_Bit)
    {
        m_HostileTerrainCostValue = rval.m_HostileTerrainCostValue;
    }

    if (rval.m_numResources > 0)
        std::copy(rval.m_Resources, rval.m_Resources + rval.m_numResources, m_Resources);

    // only replace values that have been set
    if (rval.m_MovementType)
    {
        m_MovementType = rval.m_MovementType;
    }

    // only replace values that have been set
    if (rval.m_InternalType)
    {
        m_InternalType = rval.m_InternalType;
    }

}

IconRecord const * TerrainRecord::GetIcon() const
{
    return g_theIconDB->Get(m_Icon);
}

AdvanceRecord const * TerrainRecord::GetAddAdvance() const
{
    return g_theAdvanceDB->Get(m_AddAdvance);
}

AdvanceRecord const * TerrainRecord::GetRemoveAdvance() const
{
    return g_theAdvanceDB->Get(m_RemoveAdvance);
}

sint32 TerrainRecord::GetResourcesIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numResources);
    if((index < 0) || (index >= m_numResources)) {
        return 0;
    }
    return m_Resources[index];
}

ResourceRecord const * TerrainRecord::GetResources(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numResources);
    if((index < 0) || (index >= m_numResources)) {
        return 0;
    }
    return g_theResourceDB->Get(m_Resources[index]);
}
