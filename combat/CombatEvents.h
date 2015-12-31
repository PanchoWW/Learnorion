/// \file CombatEvents.h decalares all combat events. If you need to access information in them, include this.
#ifndef COMBATEVENTS_H
#define COMBATEVENTS_H

#include <boost/shared_ptr.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>

#include "../util/Export.h"

#include "CombatEvent.h"


/// Generated when a new bout begins in the battle
struct FO_COMMON_API BoutBeginEvent : public CombatEvent {
    BoutBeginEvent();
    BoutBeginEvent(int bout);
    virtual ~BoutBeginEvent() {}

    virtual std::string DebugString() const;

    int bout;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version);
};

/// An event that describes a single attack by one object or fighter against another object or fighter
struct FO_COMMON_API AttackEvent : public CombatEvent {
    AttackEvent();
    AttackEvent(int bout, int round, int attacker_id, int target_id, float damage);

    virtual ~AttackEvent() {}

    virtual std::string DebugString() const;

    int     bout;
    int     round;
    int     attacker_id;
    int     target_id;
    float   damage;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version);
};

/// Created when an object becomes unable to fight anymore,
/// eg. a ship is destroyed or a planet loses all defence
struct FO_COMMON_API IncapacitationEvent : public CombatEvent {
    IncapacitationEvent();
    IncapacitationEvent(int bout, int object_id);
    virtual ~IncapacitationEvent() {}

    virtual std::string DebugString() const;

    int bout;
    int object_id;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version);
};

/// Created when an fighter is destroyed
struct FO_COMMON_API FighterDestructionEvent : public CombatEvent {
    FighterDestructionEvent();
    FighterDestructionEvent(int bout, int fighter_id);
    virtual ~FighterDestructionEvent() {}

    virtual std::string DebugString() const;

    int bout;
    int fighter_id;

private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version);
};


#endif // COMBATEVENT_H
