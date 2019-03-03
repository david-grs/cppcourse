template<class... Objs>
template<class Func>
void GameStore<Objs...>::ForAll(Func f)
{
    (_ForAll<Objs>(f), ...);
}

template<class... Objs>
template<class Type, class Func>
void GameStore<Objs...>::ForAllOf(Func f)
{
    (_ForAll<Objs>(f), ...);
}

template<class... Objs>
template<class Func>
void GameStore<Objs...>::RemoveIf(Func f) {
    (_RemoveIf<Objs>(f), ...);
}

template<class... Objs>
template<class Obj, class Func>
void GameStore<Objs...>::_ForAll(Func f) {
    auto &contents = std::get<std::vector<Obj>>(mContents);
    std::for_each(contents.begin(), contents.end(), f);
}

template<class... Objs>
template<class Type, class Obj, class Func>
void GameStore<Objs...>::_ForAllOf(Func f) {
    if(not std::is_base_of<Type, Obj>::value)
        return;
    auto &contents = std::get<std::vector<Obj>>(mContents);
    std::for_each(contents.begin(), contents.end(), f);
}

template<class... Objs>
template<class Obj, class Func>
void GameStore<Objs...>::_RemoveIf(Func f) {
    auto &contents = std::get<std::vector<Obj>>(mContents);
    contents.erase(std::remove_if(contents.begin(), contents.end(), f), contents.end());
    auto &lookup = std::get<std::unordered_map<ObjectId, Obj*>>(mLookup);
    std::for_each(contents.begin(), contents.end(), [&](auto& c){
                      lookup[c.GetId()] = &c;
                  });

}