
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef DIFFICULTY_RECORD_H__
#define DIFFICULTY_RECORD_H__

class DifficultyRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class TerrainImprovementRecord;
class AdvanceRecord;

#define k_Num_DifficultyRecord_Tokens 84

//
// m_flags0: Difficulty
#define k_Difficulty_NoAIProductionDeficit_Bit   0x00000001
#define k_Difficulty_NoAIGoldDeficit_Bit         0x00000002
#define k_Difficulty_AICityDefenderBonus_Bit     0x00000004
#define k_Difficulty_BarbarianCities_Bit         0x00000008
#define k_Difficulty_SectarianHappiness_Bit      0x00000010
#define k_Difficulty_RevoltCasualties_Bit        0x00000020
#define k_Difficulty_RevoltInsurgents_Bit        0x00000040
#define k_Difficulty_BarbarianSpawnsBarbarian_Bit 0x00000080
#define k_Difficulty_AINoSinking_Bit             0x00000100
#define k_Difficulty_AINoCityLimit_Bit           0x00000200
#define k_Difficulty_GoldPerUnitSupport_Bit      0x00000400
#define k_Difficulty_GoldPerCity_Bit             0x00000800
#define k_Difficulty_AINoShieldHunger_Bit        0x00001000
#define k_Difficulty_AINoGoldHunger_Bit          0x00002000
#define k_Difficulty_AIFreeUpgrade_Bit           0x00004000
#define k_Difficulty_AIMilitiaUnit_Bit           0x00008000
#define k_Difficulty_TechCostKnownDeduction_Bit  0x00010000

class DifficultyRecord : public CTPRecord
{
public:
    typedef sint32 (DifficultyRecord::*IntAccessor)() const;
    typedef bool   (DifficultyRecord::*BoolAccessor)() const;
    typedef double (DifficultyRecord::*FloatAccessor)() const ;
    typedef bool   (DifficultyRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (DifficultyRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (DifficultyRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (DifficultyRecord::*FloatArrayAccessor)(sint32 index) const;

    class Period {
    private:
        sint32            m_StartTurn;
        sint32            m_YearsPerTurn;

    public:
        Period();
        Period(CivArchive & archive){ Serialize(archive); };
        ~Period();
        Period const & operator = (Period const & rval);
        bool operator == (Period const & rval) {
          return false;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        sint32 ParseSequential(DBLexer *lex);
        sint32 ParseFullySequential(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, Period **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, Period *array, sint32 *numElements, sint32 maxSize);
        static sint32 ParseInArraySequential(DBLexer *lex, Period **array, sint32 *numElements);
        static sint32 ParseInArraySequential(DBLexer *lex, Period *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        sint32 GetStartTurn() const { return m_StartTurn; }
        sint32 GetYearsPerTurn() const { return m_YearsPerTurn; }

    }; /* class Period */

    class TimeScale {
    private:
        sint32            m_StartYear;
        sint32            m_NumPeriods;
        Period          * m_Period;
        sint32            m_numPeriod;
        sint32            m_NegativeYearFormat;
        sint32            m_PositiveYearFormat;

    public:
        TimeScale();
        TimeScale(CivArchive & archive){ Serialize(archive); };
        ~TimeScale();
        TimeScale const & operator = (TimeScale const & rval);
        bool operator == (TimeScale const & rval) {
          return false;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, TimeScale **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, TimeScale *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        sint32 GetStartYear() const { return m_StartYear; }
        sint32 GetNumPeriods() const { return m_NumPeriods; }
        const Period * GetPeriod(sint32 index) const;
        sint32 GetNumPeriod() const { return m_numPeriod;}
        sint32 GetNegativeYearFormat() const { return m_NegativeYearFormat; }
        sint32 GetPositiveYearFormat() const { return m_PositiveYearFormat; }

    }; /* class TimeScale */

    class AdvanceChance {
    private:
        sint32            m_StartAdvance; // Index into Advance database
        sint32            m_HumanChance;
        sint32            m_AIChance;

    public:
        AdvanceChance();
        AdvanceChance(CivArchive & archive){ Serialize(archive); };
        ~AdvanceChance();
        AdvanceChance const & operator = (AdvanceChance const & rval);
        bool operator == (AdvanceChance const & rval) {
          if (m_StartAdvance != rval.m_StartAdvance)
             return false;
          return true;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        sint32 ParseSequential(DBLexer *lex);
        sint32 ParseFullySequential(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, AdvanceChance **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, AdvanceChance *array, sint32 *numElements, sint32 maxSize);
        static sint32 ParseInArraySequential(DBLexer *lex, AdvanceChance **array, sint32 *numElements);
        static sint32 ParseInArraySequential(DBLexer *lex, AdvanceChance *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        sint32           GetStartAdvanceIndex() const { return m_StartAdvance; }
        AdvanceRecord const * GetStartAdvance() const;
        sint32 GetHumanChance() const { return m_HumanChance; }
        sint32 GetAIChance() const { return m_AIChance; }

    }; /* class AdvanceChance */

    class AdvanceChances {
    private:
        AdvanceChance   * m_AdvanceChance;
        sint32            m_numAdvanceChance;

    public:
        AdvanceChances();
        AdvanceChances(CivArchive & archive){ Serialize(archive); };
        ~AdvanceChances();
        AdvanceChances const & operator = (AdvanceChances const & rval);
        bool operator == (AdvanceChances const & rval) {
          return false;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, AdvanceChances **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, AdvanceChances *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        const AdvanceChance * GetAdvanceChance(sint32 index) const;
        sint32 GetNumAdvanceChance() const { return m_numAdvanceChance;}

    }; /* class AdvanceChances */

private:
    uint32 m_flags0;
    sint32            m_BaseContentment;
    sint32            m_GranaryCoeff;
    double            m_BigCityScale;
    double            m_BigCityOffset;
    sint32            m_ScienceHandicap;
    double            m_PollutionMultiplier;
    double            m_RiotChance;
    double            m_StarvationEffect;
    sint32            m_StartingGold;
    sint32            m_VisionBonus;
    sint32            m_BaseScore;
    TimeScale         m_TimeScale;
    double            m_FeatsFactor;
    double            m_AdvancesFactor;
    double            m_WondersFactor;
    double            m_Cities0To3Factor;
    double            m_Cities3To10Factor;
    double            m_Cities10To50Factor;
    double            m_Cities50PlusFactor;
    double            m_CitiesRecapturedFactor;
    double            m_PopulationFactor;
    double            m_RankFactor;
    double            m_OpponentsConqueredFactor;
    double            m_AlliesFactor;
    double            m_WonderVictoryBonus;
    double            m_SoloVictoryBonus;
    double            m_AlliedVictoryBonus;
    sint32            m_AIStartUnits;
    sint32            m_AIStartGold;
    sint32            m_AIStartAdvances;
    sint32            m_AIStartPublicWorks;
    sint32            m_HumanStartLocation;
    sint32            m_AIIntelligenceFactor;
    sint32            m_AIGangUpFactor;
    sint32            m_DistanceFromCapitolAdjustment;
    sint32            m_AIDistanceFromCapitolAdjustment;
    sint32            m_PollutionAdjust;
    double            m_AIMinBehind;
    double            m_AIMaxBehind;
    double            m_AIMinAhead;
    double            m_AIMaxAhead;
    double          * m_AIMinBehindTechnologyCost;
    sint32            m_numAIMinBehindTechnologyCost;
    double          * m_AIMaxBehindTechnologyCost;
    sint32            m_numAIMaxBehindTechnologyCost;
    double          * m_AIMinBehindProductionCostAdjustment;
    sint32            m_numAIMinBehindProductionCostAdjustment;
    double          * m_AIMaxBehindProductionCostAdjustment;
    sint32            m_numAIMaxBehindProductionCostAdjustment;
    double          * m_AIMinBehindGoldCostAdjustment;
    sint32            m_numAIMinBehindGoldCostAdjustment;
    double          * m_AIMaxBehindGoldCostAdjustment;
    sint32            m_numAIMaxBehindGoldCostAdjustment;
    double          * m_AIMinAheadTechnologyCost;
    sint32            m_numAIMinAheadTechnologyCost;
    double          * m_AIMaxAheadTechnologyCost;
    sint32            m_numAIMaxAheadTechnologyCost;
    double          * m_AIMinAheadProductionCostAdjustment;
    sint32            m_numAIMinAheadProductionCostAdjustment;
    double          * m_AIMaxAheadProductionCostAdjustment;
    sint32            m_numAIMaxAheadProductionCostAdjustment;
    double          * m_AIMinAheadGoldCostAdjustment;
    sint32            m_numAIMinAheadGoldCostAdjustment;
    double          * m_AIMaxAheadGoldCostAdjustment;
    sint32            m_numAIMaxAheadGoldCostAdjustment;
    sint32            m_MaxHumanAdvances;
    sint32            m_MaxAIAdvances;
    double            m_HumanScienceBonus;
    double            m_HumanFoodBonus;
    sint32            m_ExtraSettlerChance;
    AdvanceChances    m_AdvanceChances;
    sint32            m_PollutionStartProductionLevel;
    sint32            m_PollutionStartPopulationLevel;
    double            m_PollutionProductionRatio;
    double            m_PollutionPopulationRatio;
    sint32          * m_BarbarianCamps; // Index into TerrainImprovement database
    sint32            m_numBarbarianCamps;
    sint32            m_GoldPerUnitSupportValue;
    sint32            m_GoldPerCityValue;
    double            m_TechCostKnownDeductionValue;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    DifficultyRecord() { Init(); };
    DifficultyRecord(CivArchive &archive) { Serialize(archive); };
    DifficultyRecord(DifficultyRecord const & rval) { Init(); *this = rval; }
    ~DifficultyRecord();
    DifficultyRecord const & operator = (DifficultyRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const DifficultyRecord & rval);

    sint32 GetBaseContentment() const { return m_BaseContentment; }
    sint32 GetGranaryCoeff() const { return m_GranaryCoeff; }
    double GetBigCityScale() const { return m_BigCityScale; }
    double GetBigCityOffset() const { return m_BigCityOffset; }
    sint32 GetScienceHandicap() const { return m_ScienceHandicap; }
    double GetPollutionMultiplier() const { return m_PollutionMultiplier; }
    double GetRiotChance() const { return m_RiotChance; }
    double GetStarvationEffect() const { return m_StarvationEffect; }
    sint32 GetStartingGold() const { return m_StartingGold; }
    sint32 GetVisionBonus() const { return m_VisionBonus; }
    sint32 GetBaseScore() const { return m_BaseScore; }
    TimeScale const * GetTimeScale() const { return &m_TimeScale; }
    double GetFeatsFactor() const { return m_FeatsFactor; }
    double GetAdvancesFactor() const { return m_AdvancesFactor; }
    double GetWondersFactor() const { return m_WondersFactor; }
    double GetCities0To3Factor() const { return m_Cities0To3Factor; }
    double GetCities3To10Factor() const { return m_Cities3To10Factor; }
    double GetCities10To50Factor() const { return m_Cities10To50Factor; }
    double GetCities50PlusFactor() const { return m_Cities50PlusFactor; }
    double GetCitiesRecapturedFactor() const { return m_CitiesRecapturedFactor; }
    double GetPopulationFactor() const { return m_PopulationFactor; }
    double GetRankFactor() const { return m_RankFactor; }
    double GetOpponentsConqueredFactor() const { return m_OpponentsConqueredFactor; }
    double GetAlliesFactor() const { return m_AlliesFactor; }
    double GetWonderVictoryBonus() const { return m_WonderVictoryBonus; }
    double GetSoloVictoryBonus() const { return m_SoloVictoryBonus; }
    double GetAlliedVictoryBonus() const { return m_AlliedVictoryBonus; }
    sint32 GetAIStartUnits() const { return m_AIStartUnits; }
    sint32 GetAIStartGold() const { return m_AIStartGold; }
    sint32 GetAIStartAdvances() const { return m_AIStartAdvances; }
    sint32 GetAIStartPublicWorks() const { return m_AIStartPublicWorks; }
    sint32 GetHumanStartLocation() const { return m_HumanStartLocation; }
    sint32 GetAIIntelligenceFactor() const { return m_AIIntelligenceFactor; }
    sint32 GetAIGangUpFactor() const { return m_AIGangUpFactor; }
    sint32 GetDistanceFromCapitolAdjustment() const { return m_DistanceFromCapitolAdjustment; }
    sint32 GetAIDistanceFromCapitolAdjustment() const { return m_AIDistanceFromCapitolAdjustment; }
    sint32 GetPollutionAdjust() const { return m_PollutionAdjust; }
    double GetAIMinBehind() const { return m_AIMinBehind; }
    double GetAIMaxBehind() const { return m_AIMaxBehind; }
    double GetAIMinAhead() const { return m_AIMinAhead; }
    double GetAIMaxAhead() const { return m_AIMaxAhead; }
double     GetAIMinBehindTechnologyCost(sint32 index) const;
    sint32 GetNumAIMinBehindTechnologyCost() const { return m_numAIMinBehindTechnologyCost;}
double     GetAIMaxBehindTechnologyCost(sint32 index) const;
    sint32 GetNumAIMaxBehindTechnologyCost() const { return m_numAIMaxBehindTechnologyCost;}
double     GetAIMinBehindProductionCostAdjustment(sint32 index) const;
    sint32 GetNumAIMinBehindProductionCostAdjustment() const { return m_numAIMinBehindProductionCostAdjustment;}
double     GetAIMaxBehindProductionCostAdjustment(sint32 index) const;
    sint32 GetNumAIMaxBehindProductionCostAdjustment() const { return m_numAIMaxBehindProductionCostAdjustment;}
double     GetAIMinBehindGoldCostAdjustment(sint32 index) const;
    sint32 GetNumAIMinBehindGoldCostAdjustment() const { return m_numAIMinBehindGoldCostAdjustment;}
double     GetAIMaxBehindGoldCostAdjustment(sint32 index) const;
    sint32 GetNumAIMaxBehindGoldCostAdjustment() const { return m_numAIMaxBehindGoldCostAdjustment;}
double     GetAIMinAheadTechnologyCost(sint32 index) const;
    sint32 GetNumAIMinAheadTechnologyCost() const { return m_numAIMinAheadTechnologyCost;}
double     GetAIMaxAheadTechnologyCost(sint32 index) const;
    sint32 GetNumAIMaxAheadTechnologyCost() const { return m_numAIMaxAheadTechnologyCost;}
double     GetAIMinAheadProductionCostAdjustment(sint32 index) const;
    sint32 GetNumAIMinAheadProductionCostAdjustment() const { return m_numAIMinAheadProductionCostAdjustment;}
double     GetAIMaxAheadProductionCostAdjustment(sint32 index) const;
    sint32 GetNumAIMaxAheadProductionCostAdjustment() const { return m_numAIMaxAheadProductionCostAdjustment;}
double     GetAIMinAheadGoldCostAdjustment(sint32 index) const;
    sint32 GetNumAIMinAheadGoldCostAdjustment() const { return m_numAIMinAheadGoldCostAdjustment;}
double     GetAIMaxAheadGoldCostAdjustment(sint32 index) const;
    sint32 GetNumAIMaxAheadGoldCostAdjustment() const { return m_numAIMaxAheadGoldCostAdjustment;}
    sint32 GetMaxHumanAdvances() const { return m_MaxHumanAdvances; }
    sint32 GetMaxAIAdvances() const { return m_MaxAIAdvances; }
    double GetHumanScienceBonus() const { return m_HumanScienceBonus; }
    double GetHumanFoodBonus() const { return m_HumanFoodBonus; }
    sint32 GetExtraSettlerChance() const { return m_ExtraSettlerChance; }
    AdvanceChances const * GetAdvanceChances() const { return &m_AdvanceChances; }
    sint32 GetPollutionStartProductionLevel() const { return m_PollutionStartProductionLevel; }
    sint32 GetPollutionStartPopulationLevel() const { return m_PollutionStartPopulationLevel; }
    double GetPollutionProductionRatio() const { return m_PollutionProductionRatio; }
    double GetPollutionPopulationRatio() const { return m_PollutionPopulationRatio; }
    bool GetNoAIProductionDeficit() const { return (m_flags0 & k_Difficulty_NoAIProductionDeficit_Bit) != 0; }
    bool GetNoAIGoldDeficit() const { return (m_flags0 & k_Difficulty_NoAIGoldDeficit_Bit) != 0; }
    bool GetAICityDefenderBonus() const { return (m_flags0 & k_Difficulty_AICityDefenderBonus_Bit) != 0; }
    bool GetBarbarianCities() const { return (m_flags0 & k_Difficulty_BarbarianCities_Bit) != 0; }
    bool GetSectarianHappiness() const { return (m_flags0 & k_Difficulty_SectarianHappiness_Bit) != 0; }
    bool GetRevoltCasualties() const { return (m_flags0 & k_Difficulty_RevoltCasualties_Bit) != 0; }
    bool GetRevoltInsurgents() const { return (m_flags0 & k_Difficulty_RevoltInsurgents_Bit) != 0; }
    sint32 GetBarbarianCampsIndex(sint32 index) const;
    const TerrainImprovementRecord * GetBarbarianCamps(sint32 index) const;
    sint32 GetNumBarbarianCamps() const { return m_numBarbarianCamps;}
    bool GetBarbarianSpawnsBarbarian() const { return (m_flags0 & k_Difficulty_BarbarianSpawnsBarbarian_Bit) != 0; }
    bool GetAINoSinking() const { return (m_flags0 & k_Difficulty_AINoSinking_Bit) != 0; }
    bool GetAINoCityLimit() const { return (m_flags0 & k_Difficulty_AINoCityLimit_Bit) != 0; }
    bool HasGoldPerUnitSupport() const { return (m_flags0 & k_Difficulty_GoldPerUnitSupport_Bit) != 0; }
    bool GetGoldPerUnitSupport(sint32 & value) const
    {
        if (m_flags0 & k_Difficulty_GoldPerUnitSupport_Bit)
        {
            value = m_GoldPerUnitSupportValue;
        }
        return (m_flags0 & k_Difficulty_GoldPerUnitSupport_Bit) != 0;
    }
    bool HasGoldPerCity() const { return (m_flags0 & k_Difficulty_GoldPerCity_Bit) != 0; }
    bool GetGoldPerCity(sint32 & value) const
    {
        if (m_flags0 & k_Difficulty_GoldPerCity_Bit)
        {
            value = m_GoldPerCityValue;
        }
        return (m_flags0 & k_Difficulty_GoldPerCity_Bit) != 0;
    }
    bool GetAINoShieldHunger() const { return (m_flags0 & k_Difficulty_AINoShieldHunger_Bit) != 0; }
    bool GetAINoGoldHunger() const { return (m_flags0 & k_Difficulty_AINoGoldHunger_Bit) != 0; }
    bool GetAIFreeUpgrade() const { return (m_flags0 & k_Difficulty_AIFreeUpgrade_Bit) != 0; }
    bool GetAIMilitiaUnit() const { return (m_flags0 & k_Difficulty_AIMilitiaUnit_Bit) != 0; }
    bool HasTechCostKnownDeduction() const { return (m_flags0 & k_Difficulty_TechCostKnownDeduction_Bit) != 0; }
    bool GetTechCostKnownDeduction(double & value) const
    {
        if (m_flags0 & k_Difficulty_TechCostKnownDeduction_Bit)
        {
            value = m_TechCostKnownDeductionValue;
        }
        return (m_flags0 & k_Difficulty_TechCostKnownDeduction_Bit) != 0;
    }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* DifficultyRecord */

struct DifficultyRecordAccessorInfo
{
    DifficultyRecord::IntAccessor        m_intAccessor;
    DifficultyRecord::BoolAccessor       m_boolAccessor;
    DifficultyRecord::FloatAccessor      m_floatAccessor;
    DifficultyRecord::BitIntAccessor     m_bitIntAccessor;
    DifficultyRecord::BitFloatAccessor   m_bitFloatAccessor;
    DifficultyRecord::IntArrayAccessor   m_intArrayAccessor;
    DifficultyRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern DifficultyRecordAccessorInfo      g_DifficultyRecord_Accessors[];
extern CTPDatabase<DifficultyRecord> *   g_theDifficultyDB;

extern const char * g_Difficulty_Tokens[];

#endif
