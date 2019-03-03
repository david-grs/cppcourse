#include "utils.h"
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>
/*
 * Holds a vector of each provided type, along with a lookup table to provide stable access to the vector elements.
 */
template<class ...Objs>
class GameStore {
public:

    //Reallocating the vector would invalidate the lookup table.
    GameStore() {
        (_Reserve<Objs>(1024), ...);
    }


    template<class Func>
    void ForAll(Func f);

    template<class Type, class Func>
    void ForAllOf(Func f);


    template<class Func>
    void RemoveIf(Func f);

    template<class Obj, class ...Args>
    ObjectId Create(Args ...args) {
        Obj& newObject = std::get<std::vector<Obj>>(mContents).emplace_back(args...);
        std::get<std::unordered_map<ObjectId, Obj*>>(mLookup).insert({newObject.GetId(), &newObject});
        return newObject.GetId();
    }

    template<class Object>
    Object& Get(ObjectId id)
    {
        return *std::get<std::unordered_map<ObjectId, Object*>>(mLookup)[id];
    }

private:

    std::tuple<std::vector<Objs>...> mContents;
    std::tuple<std::unordered_map<ObjectId, Objs*>...> mLookup;

    template<class Object>
    void _Reserve(size_t count)
    {
        std::get<std::vector<Object>>(mContents).reserve(count);
    }

    template<class Object, class Func>
    void _ForAll(Func f);
    template<class Type, class Object, class Func>
    void _ForAllOf(Func f);
    template<class Object, class Func>
    void _RemoveIf(Func f);
};

#include "game_store.tcc"