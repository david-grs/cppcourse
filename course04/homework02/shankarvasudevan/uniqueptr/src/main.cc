#include <iostream>

class UniquePtrInt
{
    public:
        UniquePtrInt(std::size_t value)
        {
            mData = new std::size_t(value);
        }

        ~UniquePtrInt()
        {
            delete mData;
        }

        std::size_t* get() 
        { 
            std::size_t* mDataCpy = mData;
            return mDataCpy; 
        }

        std::size_t* release() 
        { 
            std::size_t* mDataCpy = mData;
            delete mData;
            return mDataCpy;
        }

        void operator=(UniquePtrInt other)
        {
            // TODO: Need to do this properly
        }

        

    private:
        std::size_t* mData = nullptr;
};


int main()
{
    std::cout << "Create a new pointer" << std::endl;

    std::size_t x(10);
    std::size_t y(20);

    UniquePtrInt p1(x);
    UniquePtrInt p2(y);
    UniquePtrInt p3(x);

    std::cout << "Compare the addresses of the pointers" << std::endl;

    std::cout << "P1.Get:" << p1.get() << std::endl;
    std::cout << "P2.Get:" << p2.get() << std::endl;
    std::cout << "P3.Get:" << p3.get() << std::endl;

    std::cout << "Getting the values from each pointer" << std::endl;

    std::cout << "P1.Value:" << *(p1.get()) << std::endl;
    std::cout << "P2.Value:" << *(p2.get()) << std::endl;
    std::cout << "P3.Value:" << *(p3.get()) << std::endl;

    std::cout << "Releasing the pointers" << std::endl;

    std::size_t* x1 = p1.release();
    std::size_t* y1 = p2.release();
    std::size_t* x2 = p3.release();

    std::cout << "X1:" << *x1 << std::endl;
    std::cout << "Y1:" << *y1 << std::endl;
    std::cout << "X2:" << *x2 << std::endl;

    std::cout << "P1.Get" << p1.get() << std::endl;
    std::cout << "P2.Get" << p2.get() << std::endl;
    std::cout << "P3.Get" << p3.get() << std::endl;
    
    return 0;
}