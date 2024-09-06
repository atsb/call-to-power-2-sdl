
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "GlobalWarmingRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "TerrainRecord.h"
#include "TerrainRecord.h"

CTPDatabase<GlobalWarmingRecord> *g_theGlobalWarmingDB = NULL;

void GlobalWarmingRecord::Init()
{
    m_ChangeTypeProbability = NULL;
    m_numChangeTypeProbability = 0;
    m_PollutionNextToOcean = 0;
    m_PollutionNeighbourBonus = 0;
    m_PollutionMaxBonus = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void GlobalWarmingRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }

        {
            archive << m_numChangeTypeProbability;
            for(sint32 i = 0; i < m_numChangeTypeProbability; ++i){
                m_ChangeTypeProbability[i].Serialize(archive);
            }
        }

        archive << m_PollutionNextToOcean;
        archive << m_PollutionNeighbourBonus;
        archive << m_PollutionMaxBonus;
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

        {
            archive >> m_numChangeTypeProbability;
            m_ChangeTypeProbability = new ChangeTypeProbability[m_numChangeTypeProbability];
            for(sint32 i = 0; i < m_numChangeTypeProbability; ++i){
                m_ChangeTypeProbability[i].Serialize(archive);
            }
        }

        archive >> m_PollutionNextToOcean;
        archive >> m_PollutionNeighbourBonus;
        archive >> m_PollutionMaxBonus;
    }
}

GlobalWarmingRecord::~GlobalWarmingRecord()
{
    delete [] m_ChangeTypeProbability;
}

GlobalWarmingRecord const & GlobalWarmingRecord::operator = (GlobalWarmingRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_ChangeTypeProbability;
        m_ChangeTypeProbability = NULL;
        if (rval.m_numChangeTypeProbability > 0)
        {
            m_ChangeTypeProbability = new ChangeTypeProbability [rval.m_numChangeTypeProbability];
            std::copy(rval.m_ChangeTypeProbability, rval.m_ChangeTypeProbability + rval.m_numChangeTypeProbability, m_ChangeTypeProbability);
        }
        m_numChangeTypeProbability = rval.m_numChangeTypeProbability;

        m_PollutionNextToOcean = rval.m_PollutionNextToOcean;

        m_PollutionNeighbourBonus = rval.m_PollutionNeighbourBonus;

        m_PollutionMaxBonus = rval.m_PollutionMaxBonus;

    }

    return *this;
}

const char *g_GlobalWarming_Tokens[] =
{
    "ChangeTypeProbability",
    "PollutionNextToOcean",
    "PollutionNeighbourBonus",
    "PollutionMaxBonus",
    "POLLUTION_NEXT_TO_OCEAN",
    "POLLUTION_NEIGHBOUR_BONUS",
    "POLLUTION_MAX_BONUS",
};

GlobalWarmingRecordAccessorInfo g_GlobalWarmingRecord_Accessors[] =
{
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* ChangeTypeProbability */
    { &GlobalWarmingRecord::GetPollutionNextToOcean, NULL, NULL, NULL, NULL, NULL, NULL },
    { &GlobalWarmingRecord::GetPollutionNeighbourBonus, NULL, NULL, NULL, NULL, NULL, NULL },
    { &GlobalWarmingRecord::GetPollutionMaxBonus, NULL, NULL, NULL, NULL, NULL, NULL },
};

#define k_Token_GlobalWarming_ChangeTypeProbability ((k_Token_Custom_Base) + 0)
#define k_Token_GlobalWarming_PollutionNextToOcean ((k_Token_Custom_Base) + 1)
#define k_Token_GlobalWarming_PollutionNeighbourBonus ((k_Token_Custom_Base) + 2)
#define k_Token_GlobalWarming_PollutionMaxBonus  ((k_Token_Custom_Base) + 3)
#define k_Token_GlobalWarming_POLLUTION_NEXT_TO_OCEAN ((k_Token_Custom_Base) + 4)
#define k_Token_GlobalWarming_POLLUTION_NEIGHBOUR_BONUS ((k_Token_Custom_Base) + 5)
#define k_Token_GlobalWarming_POLLUTION_MAX_BONUS ((k_Token_Custom_Base) + 6)
#define k_Token_GlobalWarming_Max                ((k_Token_Custom_Base) + 7)


static BitArray s_ParsedTokens(7);
void GlobalWarmingRecord::CheckRequiredFields(DBLexer *lex)
{
    if(!s_ParsedTokens.Bit(k_Token_GlobalWarming_PollutionNextToOcean - k_Token_Custom_Base)
    && !s_ParsedTokens.Bit(k_Token_GlobalWarming_POLLUTION_NEXT_TO_OCEAN - k_Token_Custom_Base)
    ){
        DBERROR(("Warning: required field PollutionNextToOcean missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_GlobalWarming_PollutionNeighbourBonus - k_Token_Custom_Base)
    && !s_ParsedTokens.Bit(k_Token_GlobalWarming_POLLUTION_NEIGHBOUR_BONUS - k_Token_Custom_Base)
    ){
        DBERROR(("Warning: required field PollutionNeighbourBonus missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_GlobalWarming_PollutionMaxBonus - k_Token_Custom_Base)
    && !s_ParsedTokens.Bit(k_Token_GlobalWarming_POLLUTION_MAX_BONUS - k_Token_Custom_Base)
    ){
        DBERROR(("Warning: required field PollutionMaxBonus missing"));
    }
}

sint32 GlobalWarmingRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_GlobalWarming_Tokens, k_Token_GlobalWarming_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "GLOBALWARMING_%i", numRecords);
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
        if(tok >= k_Token_Custom_Base && tok < k_Token_GlobalWarming_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_GlobalWarming_ChangeTypeProbability:
                if(!GlobalWarmingRecord::ChangeTypeProbability::ParseInArray(lex, &m_ChangeTypeProbability, &m_numChangeTypeProbability))
                {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_PollutionNextToOcean:
            case k_Token_GlobalWarming_POLLUTION_NEXT_TO_OCEAN:
                if(!lex->GetIntAssignment(m_PollutionNextToOcean)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_PollutionNeighbourBonus:
            case k_Token_GlobalWarming_POLLUTION_NEIGHBOUR_BONUS:
                if(!lex->GetIntAssignment(m_PollutionNeighbourBonus)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_PollutionMaxBonus:
            case k_Token_GlobalWarming_POLLUTION_MAX_BONUS:
                if(!lex->GetIntAssignment(m_PollutionMaxBonus)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!GlobalWarmingRecord::ChangeTypeProbability::ParseInArray(lex, &m_ChangeTypeProbability, &m_numChangeTypeProbability)) {
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

void GlobalWarmingRecord::ResolveDBReferences()
{
    {
        sint32 i;
        for(i = 0; i < m_numChangeTypeProbability; i++) {
            m_ChangeTypeProbability[i].ResolveDBReferences();
        }
    }
}

GlobalWarmingRecord::ChangeTypeProbability::ChangeTypeProbability()
{
    m_flags0 = 0;
    m_POLLUTION_TILE_DESERT = -1.000000;
    m_POLLUTION_TILE_FOREST = -1.000000;
    m_POLLUTION_TILE_GLACIER = -1.000000;
    m_POLLUTION_TILE_GRASSLAND = -1.000000;
    m_POLLUTION_TILE_HILL = -1.000000;
    m_POLLUTION_TILE_JUNGLE = -1.000000;
    m_POLLUTION_TILE_MOUNTAIN = -1.000000;
    m_POLLUTION_TILE_BROWN_HILL = -1.000000;
    m_POLLUTION_TILE_BROWN_MOUNTAIN = -1.000000;
    m_POLLUTION_TILE_WHITE_HILL = -1.000000;
    m_POLLUTION_TILE_WHITE_MOUNTAIN = -1.000000;
    m_POLLUTION_TILE_PLAINS = -1.000000;
    m_POLLUTION_TILE_SWAMP = -1.000000;
    m_POLLUTION_TILE_TUNDRA = -1.000000;
    m_FromTypeValue = 0;
    m_ToTypeValue = 0;
    m_ProbabilityValue = 0.000000;
}

GlobalWarmingRecord::ChangeTypeProbability::~ChangeTypeProbability()
{
}

GlobalWarmingRecord::ChangeTypeProbability const & GlobalWarmingRecord::ChangeTypeProbability::operator = (ChangeTypeProbability const & rval)
{
    if (this != &rval)
    {
        m_flags0 = rval.m_flags0;

        m_POLLUTION_TILE_DESERT = rval.m_POLLUTION_TILE_DESERT;

        m_POLLUTION_TILE_FOREST = rval.m_POLLUTION_TILE_FOREST;

        m_POLLUTION_TILE_GLACIER = rval.m_POLLUTION_TILE_GLACIER;

        m_POLLUTION_TILE_GRASSLAND = rval.m_POLLUTION_TILE_GRASSLAND;

        m_POLLUTION_TILE_HILL = rval.m_POLLUTION_TILE_HILL;

        m_POLLUTION_TILE_JUNGLE = rval.m_POLLUTION_TILE_JUNGLE;

        m_POLLUTION_TILE_MOUNTAIN = rval.m_POLLUTION_TILE_MOUNTAIN;

        m_POLLUTION_TILE_BROWN_HILL = rval.m_POLLUTION_TILE_BROWN_HILL;

        m_POLLUTION_TILE_BROWN_MOUNTAIN = rval.m_POLLUTION_TILE_BROWN_MOUNTAIN;

        m_POLLUTION_TILE_WHITE_HILL = rval.m_POLLUTION_TILE_WHITE_HILL;

        m_POLLUTION_TILE_WHITE_MOUNTAIN = rval.m_POLLUTION_TILE_WHITE_MOUNTAIN;

        m_POLLUTION_TILE_PLAINS = rval.m_POLLUTION_TILE_PLAINS;

        m_POLLUTION_TILE_SWAMP = rval.m_POLLUTION_TILE_SWAMP;

        m_POLLUTION_TILE_TUNDRA = rval.m_POLLUTION_TILE_TUNDRA;

        m_FromTypeValue = rval.m_FromTypeValue;

        m_ToTypeValue = rval.m_ToTypeValue;

        m_ProbabilityValue = rval.m_ProbabilityValue;

    }

    return *this;
}

void GlobalWarmingRecord::ChangeTypeProbability::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_flags0;
        archive << m_POLLUTION_TILE_DESERT;
        archive << m_POLLUTION_TILE_FOREST;
        archive << m_POLLUTION_TILE_GLACIER;
        archive << m_POLLUTION_TILE_GRASSLAND;
        archive << m_POLLUTION_TILE_HILL;
        archive << m_POLLUTION_TILE_JUNGLE;
        archive << m_POLLUTION_TILE_MOUNTAIN;
        archive << m_POLLUTION_TILE_BROWN_HILL;
        archive << m_POLLUTION_TILE_BROWN_MOUNTAIN;
        archive << m_POLLUTION_TILE_WHITE_HILL;
        archive << m_POLLUTION_TILE_WHITE_MOUNTAIN;
        archive << m_POLLUTION_TILE_PLAINS;
        archive << m_POLLUTION_TILE_SWAMP;
        archive << m_POLLUTION_TILE_TUNDRA;
        archive << m_FromTypeValue;
        archive << m_ToTypeValue;
        archive << m_ProbabilityValue;
    } else {
        archive >> m_flags0;
        archive >> m_POLLUTION_TILE_DESERT;
        archive >> m_POLLUTION_TILE_FOREST;
        archive >> m_POLLUTION_TILE_GLACIER;
        archive >> m_POLLUTION_TILE_GRASSLAND;
        archive >> m_POLLUTION_TILE_HILL;
        archive >> m_POLLUTION_TILE_JUNGLE;
        archive >> m_POLLUTION_TILE_MOUNTAIN;
        archive >> m_POLLUTION_TILE_BROWN_HILL;
        archive >> m_POLLUTION_TILE_BROWN_MOUNTAIN;
        archive >> m_POLLUTION_TILE_WHITE_HILL;
        archive >> m_POLLUTION_TILE_WHITE_MOUNTAIN;
        archive >> m_POLLUTION_TILE_PLAINS;
        archive >> m_POLLUTION_TILE_SWAMP;
        archive >> m_POLLUTION_TILE_TUNDRA;
        archive >> m_FromTypeValue;
        archive >> m_ToTypeValue;
        archive >> m_ProbabilityValue;
    }
}

static const char *s_GlobalWarming_ChangeTypeProbability_Tokens[] = {
    "POLLUTION_TILE_DESERT",
    "POLLUTION_TILE_FOREST",
    "POLLUTION_TILE_GLACIER",
    "POLLUTION_TILE_GRASSLAND",
    "POLLUTION_TILE_HILL",
    "POLLUTION_TILE_JUNGLE",
    "POLLUTION_TILE_MOUNTAIN",
    "POLLUTION_TILE_BROWN_HILL",
    "POLLUTION_TILE_BROWN_MOUNTAIN",
    "POLLUTION_TILE_WHITE_HILL",
    "POLLUTION_TILE_WHITE_MOUNTAIN",
    "POLLUTION_TILE_PLAINS",
    "POLLUTION_TILE_SWAMP",
    "POLLUTION_TILE_TUNDRA",
    "POLLUTION_TILE_TO_PLAINS",
    "POLLUTION_TILE_TO_JUNGLE",
    "POLLUTION_TILE_TO_TUNDRA",
    "POLLUTION_TILE_TO_FOREST",
    "POLLUTION_TILE_TO_DESERT",
    "POLLUTION_TILE_TO_SWAMP",
    "POLLUTION_TILE_TO_MOUNTAIN",
    "POLLUTION_TILE_TO_BROWN_HILL",
    "POLLUTION_TILE_TO_BROWN_MOUNTAIN",
    "POLLUTION_TILE_TO_WHITE_HILL",
    "POLLUTION_TILE_TO_WHITE_MOUNTAIN",
    "POLLUTION_TILE_TO_GRASSLAND",
    "POLLUTION_TILE_TO_OCEAN",
    "FromType",
    "ToType",
    "Probability",
};
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_DESERT ((k_Token_Custom_Base) + 0)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_FOREST ((k_Token_Custom_Base) + 1)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GLACIER ((k_Token_Custom_Base) + 2)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GRASSLAND ((k_Token_Custom_Base) + 3)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_HILL ((k_Token_Custom_Base) + 4)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_JUNGLE ((k_Token_Custom_Base) + 5)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_MOUNTAIN ((k_Token_Custom_Base) + 6)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_HILL ((k_Token_Custom_Base) + 7)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_MOUNTAIN ((k_Token_Custom_Base) + 8)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_HILL ((k_Token_Custom_Base) + 9)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_MOUNTAIN ((k_Token_Custom_Base) + 10)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_PLAINS ((k_Token_Custom_Base) + 11)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_SWAMP ((k_Token_Custom_Base) + 12)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TUNDRA ((k_Token_Custom_Base) + 13)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_PLAINS ((k_Token_Custom_Base) + 14)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_JUNGLE ((k_Token_Custom_Base) + 15)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_TUNDRA ((k_Token_Custom_Base) + 16)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_FOREST ((k_Token_Custom_Base) + 17)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_DESERT ((k_Token_Custom_Base) + 18)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_SWAMP ((k_Token_Custom_Base) + 19)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_MOUNTAIN ((k_Token_Custom_Base) + 20)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_HILL ((k_Token_Custom_Base) + 21)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_MOUNTAIN ((k_Token_Custom_Base) + 22)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_HILL ((k_Token_Custom_Base) + 23)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_MOUNTAIN ((k_Token_Custom_Base) + 24)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_GRASSLAND ((k_Token_Custom_Base) + 25)
#define k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_OCEAN ((k_Token_Custom_Base) + 26)
#define k_Token_GlobalWarming_ChangeTypeProbability_FromType ((k_Token_Custom_Base) + 27)
#define k_Token_GlobalWarming_ChangeTypeProbability_ToType ((k_Token_Custom_Base) + 28)
#define k_Token_GlobalWarming_ChangeTypeProbability_Probability ((k_Token_Custom_Base) + 29)
#define k_Token_GlobalWarming_ChangeTypeProbability_Max ((k_Token_Custom_Base) + 30)
sint32 GlobalWarmingRecord::ChangeTypeProbability::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    sint32 result = 0;
    tok = lex->PeekAhead();
    if(tok != k_Token_OpenBrace) {
        if(lex->GetCurrentToken() != k_Token_OpenBrace) {
            if(ParseNum(lex)) {
                return 1;
            }
            DBERROR(("Expected open brace for ChangeTypeProbability"));
            return 0;
        }
    }
    else {
        tok = lex->GetToken();
    }
    lex->SetTokens(s_GlobalWarming_ChangeTypeProbability_Tokens, k_Token_GlobalWarming_ChangeTypeProbability_Max);
    while(!done) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_DESERT:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_DESERT)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_FOREST:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_FOREST)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GLACIER:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_GLACIER)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GRASSLAND:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_GRASSLAND)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_JUNGLE:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_JUNGLE)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_BROWN_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_BROWN_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_WHITE_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_WHITE_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_PLAINS:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_PLAINS)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_SWAMP:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_SWAMP)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TUNDRA:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_TUNDRA)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_PLAINS:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_PLAINS_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_JUNGLE:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_JUNGLE_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_TUNDRA:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_TUNDRA_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_FOREST:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_FOREST_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_DESERT:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_DESERT_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_SWAMP:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_SWAMP_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_HILL:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_HILL_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_HILL:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_HILL_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_GRASSLAND:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_GRASSLAND_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_OCEAN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_OCEAN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_FromType:
                m_flags0 |= k_ChangeTypeProbability_FromType_Bit;
                if(!g_theTerrainDB->GetRecordFromLexer(lex, m_FromTypeValue)) {
                    DBERROR(("Expected record"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_ToType:
                m_flags0 |= k_ChangeTypeProbability_ToType_Bit;
                if(!g_theTerrainDB->GetRecordFromLexer(lex, m_ToTypeValue)) {
                    DBERROR(("Expected record"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_Probability:
                m_flags0 |= k_ChangeTypeProbability_Probability_Bit;
                if(!lex->GetFloatAssignment(m_ProbabilityValue)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                if(!lex->GetFloat(m_POLLUTION_TILE_DESERT)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    lex->RestoreTokens();
    return result;
}

sint32 GlobalWarmingRecord::ChangeTypeProbability::ParseInArray(DBLexer *lex, ChangeTypeProbability **array, sint32 *numElements)
{
    if(*numElements > 0) {
        ChangeTypeProbability *oldArray = *array;
        *array = new ChangeTypeProbability[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++)
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new ChangeTypeProbability[1];
    }
    (*array)[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

sint32 GlobalWarmingRecord::ChangeTypeProbability::ParseInArray(DBLexer *lex, ChangeTypeProbability *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}

sint32 GlobalWarmingRecord::ChangeTypeProbability::ParseNum(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    lex->SetTokens(s_GlobalWarming_ChangeTypeProbability_Tokens, k_Token_GlobalWarming_ChangeTypeProbability_Max);
    for(sint32 i = 0; i < 2; ++i) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_DESERT:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_DESERT)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_FOREST:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_FOREST)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GLACIER:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_GLACIER)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_GRASSLAND:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_GRASSLAND)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_JUNGLE:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_JUNGLE)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_BROWN_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_BROWN_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_BROWN_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_HILL:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_WHITE_HILL)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_WHITE_MOUNTAIN:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_WHITE_MOUNTAIN)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_PLAINS:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_PLAINS)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_SWAMP:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_SWAMP)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TUNDRA:
                if(!lex->GetFloatAssignment(m_POLLUTION_TILE_TUNDRA)) {
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_PLAINS:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_PLAINS_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_JUNGLE:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_JUNGLE_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_TUNDRA:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_TUNDRA_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_FOREST:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_FOREST_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_DESERT:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_DESERT_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_SWAMP:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_SWAMP_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_HILL:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_HILL_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_BROWN_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_HILL:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_HILL_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_MOUNTAIN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_WHITE_MOUNTAIN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_GRASSLAND:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_GRASSLAND_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_POLLUTION_TILE_TO_OCEAN:
                m_flags0 |= k_ChangeTypeProbability_POLLUTION_TILE_TO_OCEAN_Bit;
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_FromType:
                m_flags0 |= k_ChangeTypeProbability_FromType_Bit;
                if(!g_theTerrainDB->GetRecordFromLexer(lex, m_FromTypeValue)) {
                    DBERROR(("Expected record"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_ToType:
                m_flags0 |= k_ChangeTypeProbability_ToType_Bit;
                if(!g_theTerrainDB->GetRecordFromLexer(lex, m_ToTypeValue)) {
                    DBERROR(("Expected record"));
                    done = true; break;
                }
                break;
            case k_Token_GlobalWarming_ChangeTypeProbability_Probability:
                m_flags0 |= k_ChangeTypeProbability_Probability_Bit;
                if(!lex->GetFloatAssignment(m_ProbabilityValue)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            default:
                if(!lex->GetFloat(m_POLLUTION_TILE_DESERT)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    lex->RestoreTokens();

    if(done)
        return 0;

    return 1;
}

void GlobalWarmingRecord::ChangeTypeProbability::ResolveDBReferences()
{
}

void GlobalWarmingRecord::Merge(const GlobalWarmingRecord & rval){
    // replace struct elements of m_ChangeTypeProbability
    for (sint32 index_ChangeTypeProbability = 0; index_ChangeTypeProbability < m_numChangeTypeProbability; ++index_ChangeTypeProbability)
    {
        // find matching struct element and replace it
        for (sint32 obj_index = 0; obj_index < rval.m_numChangeTypeProbability; ++obj_index)
            if (m_ChangeTypeProbability[index_ChangeTypeProbability] == rval.m_ChangeTypeProbability[obj_index]){
                m_ChangeTypeProbability[index_ChangeTypeProbability] = rval.m_ChangeTypeProbability[obj_index];
            }
    }
}

GlobalWarmingRecord::ChangeTypeProbability const * GlobalWarmingRecord::GetChangeTypeProbability(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numChangeTypeProbability);
    if((index < 0) || (index >= m_numChangeTypeProbability)) {
        return 0;
    }
    return &m_ChangeTypeProbability[index];
}

const TerrainRecord *GlobalWarmingRecord::ChangeTypeProbability::GetFromTypePtr() const
{
    return g_theTerrainDB->Get(m_FromTypeValue);
}

const TerrainRecord *GlobalWarmingRecord::ChangeTypeProbability::GetToTypePtr() const
{
    return g_theTerrainDB->Get(m_ToTypeValue);
}
