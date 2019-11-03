#include <iostream>
#include <vector>
#include <functional>

class PriceListener;

class SubscriptionHandle
{
public:
	explicit SubscriptionHandle(std::function<void()> atExit) :
		mAtExit(atExit)
	{}

	~SubscriptionHandle()
	{
		mAtExit();
	}

	SubscriptionHandle(const SubscriptionHandle&) =delete;

private:
	std::function<void()> mAtExit;
};



class PriceSource
{
public:
	SubscriptionHandle Subscribe(PriceListener* listener)
	{
		const std::size_t idx = mListeners.size();
		mListeners.push_back(listener);
		return SubscriptionHandle{[=]() { mListeners[idx] = nullptr; }};
	}

	void NewPrice(double price);

private:
	std::vector<PriceListener*> mListeners;
};

class PriceListener
{
public:
	explicit PriceListener(PriceSource& source) :
		mSource(source),
		mHandle{mSource.Subscribe(this)}
	{
	}

	// no need dtor: less code, performance
	// Unsubscribe()

	void OnPrice(double price)
	{
		std::cout << "new price: " << price << std::endl;
		mPrices.push_back(price);
	}

private:
	PriceSource& mSource;
	std::vector<double> mPrices;
	SubscriptionHandle mHandle;
};

void PriceSource::NewPrice(double price)
{
	for (const auto& listener : mListeners)
	{
		if (listener)
			listener->OnPrice(price);
	}
}


int main()
{
	PriceSource source;
	PriceListener listener{source};
	PriceListener listener2 = listener;

	source.NewPrice(10);
	source.NewPrice(1);
	source.NewPrice(120);

	return 0;
}
