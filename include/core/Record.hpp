#pragma once

#include <string>
#include <vector>

struct Record
{
    std::string id;

    std::string firstName;
    std::string lastName;
    std::string otherName;

    std::string metadata;

    std::vector<std::string> toVector() const
    {
        return {
            id,
            firstName,
            lastName,
            otherName,
            metadata
        };
    }

    static Record fromVector(const std::vector<std::string>& v)
    {
        Record r;

        if(v.size() > 0) r.id = v[0];
        if(v.size() > 1) r.firstName = v[1];
        if(v.size() > 2) r.lastName = v[2];
        if(v.size() > 3) r.otherName = v[3];
        if(v.size() > 4) r.metadata = v[4];

        return r;
    }
};