#include <set>
#include <unordered_set>
#include <vector>
#include <random>
#include <algorithm>

static std::uniform_int_distribution<int> dist{0, 10000};

static void Set(benchmark::State& state) 
{
  std::mt19937 mt{0xdeadbeef};

  std::set<int> s;
  for (int i = 0; i < state.range(0); ++i)
    s.emplace(i);

  for (auto _ : state) 
  {
    auto it = s.find(dist(mt));
    benchmark::DoNotOptimize(&it);
  }
}
BENCHMARK(Set)->Arg(32)->Arg(128)->Arg(256);


static void USet(benchmark::State& state) 
{
  std::mt19937 mt{0xdeadbeef};

  std::unordered_set<int> s;
  for (int i = 0; i < state.range(0); ++i)
    s.emplace(i);

  for (auto _ : state) 
  {
    auto it = s.find(dist(mt));
    benchmark::DoNotOptimize(&it);
  }
}
BENCHMARK(USet)->Arg(32)->Arg(128)->Arg(256);



static void Vector(benchmark::State& state) 
{
  std::mt19937 mt{0xdeadbeef};

  std::vector<int> s;
  for (int i = 0; i < state.range(0); ++i)
    s.push_back(i);

  for (auto _ : state) 
  {
    auto it = std::find(s.cbegin(), s.cend(), dist(mt));
    benchmark::DoNotOptimize(&it);
  }
}
BENCHMARK(Vector)->Arg(32)->Arg(128)->Arg(256);




static void SVector(benchmark::State& state) 
{
  std::mt19937 mt{0xdeadbeef};

  std::vector<int> s;
  for (int i = 0; i < state.range(0); ++i)
    s.push_back(i);

  std::sort(s.begin(), s.begin());

  for (auto _ : state) 
  {
    auto it = std::lower_bound(s.cbegin(), s.cend(), dist(mt));
    benchmark::DoNotOptimize(&it);
  }
}
BENCHMARK(SVector)->Arg(32)->Arg(128)->Arg(256);


