/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GUILDMGR_H
#define _GUILDMGR_H

#include "Guild.h"

struct GuildChallengeReward
{
    uint32 Gold;
    uint32 ChallengeCount;
    uint32 Gold2;
};
typedef std::vector<GuildChallengeReward> GuildChallengeRewardData;

class TC_GAME_API GuildMgr
{
    GuildMgr();
    ~GuildMgr();

public:
    typedef std::unordered_map<ObjectGuid::LowType, Guild*> GuildContainer;

    static GuildMgr* instance();

    Guild* GetGuildByLeader(ObjectGuid const& guid) const;
    Guild* GetGuildById(ObjectGuid::LowType guildId) const;
    Guild* GetGuildByGuid(ObjectGuid const& guid) const;
    Guild* GetGuildByName(std::string const& guildName) const;
    std::string GetGuildNameById(ObjectGuid::LowType const& guildId) const;

    void LoadGuildXpForLevel();
    void LoadGuildRewards();
    void LoadGuildChallengeRewardInfo();

    void LoadGuilds();
    void AddGuild(Guild* guild);
    void RemoveGuild(ObjectGuid::LowType guildId);

    void SaveGuilds();
    void UnloadAll();

    ObjectGuid::LowType GenerateGuildId();
    void SetNextGuildId(ObjectGuid::LowType Id);
    std::vector<GuildReward> const& GetGuildRewards() const;

    GuildChallengeRewardData const& GetGuildChallengeRewardData() const;

protected:
    ObjectGuid::LowType NextGuildId;
    GuildContainer GuildStore;
    std::vector<uint64> GuildXPperLevel;
    std::vector<GuildReward> GuildRewards;
    GuildChallengeRewardData _challengeRewardData;
};

#define sGuildMgr GuildMgr::instance()

#endif
