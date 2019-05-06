# include <iostream>

class Date
{
	private: int y,m,d;
			 bool yearvalid(){
				 if (y>2500 || y<1600) {
					 return false;}
				 return true;}
			 bool monthvalid(){
				 if (m<0 || m>12){return false;}
				 return true;
			 }
			 bool isleapyear(int y){
				 if (y %4 != 0){return false;}
				 if (y %100 !=0) {return true;}
				 if (y%400 !=0) {return false;}
				 return true;
			 }
			 int maxDayInMonth(int y, int m){
				 if (m==1 || m==3 || m==5 || m==7|| m==8||m==10 || m==12){return 31;}
				 if (m==4 || m==6|| m==9 || m==11){return 30;}
				 if (isleapyear(y)){return 29;}
				 return 28;
			 }
			 int dayDiff(Date first, Date second){
				 if (first==second){return 0;}
				 if (!(first<second)){return -1 *dayDiff(second, first);}

				 Date dayCnt = first.nextDay();
				 int cnt = 1;
				while (dayCnt<second ){
					cnt++;
					dayCnt = dayCnt.nextDay();
				}
				return cnt;
			 }
	public:
		Date (int y, int m, int d): y(y), m(m), d(d)
	{
	};
		Date nextDay() {
			Date firstguess = {y,m,d+1};
			if (!firstguess.isValid())
			{
				firstguess = {y,m+1,1};
				if (!firstguess.isValid())
				{
					firstguess = {y+1,1,1};
				}
			}
			return firstguess;
		}
		bool isValid(){
			if (!yearvalid() || !monthvalid()) {return false;}
			if (d<1 || d>maxDayInMonth(y,m)) {return false;}
			return true;
		}
		int getY() const {return y;}
		int getM() const {return m;}
		int getD() const {return d;}

		bool operator==(Date other){
			if (y==other.getY() && m==other.getM() && d==other.getD()){return true;}
			return false;
		}
		bool operator<(Date other){
			if (y>other.getY()){ return false;}
			if (y<other.getY()){ return true;}
			if (m>other.getM()){ return false;}
			if (m<other.getM()){ return true;}
			if (d<other.getD()){ return true;}
			return false;
		}
		int daysSinceEpoch(){
			Date epoch = {1970,1,1};
			return dayDiff(epoch, *this);
		}

		std::string dayOfWeek(){
			std::string retval ="unknown";
			if (!isValid()){
				retval="Invalid date";
				return retval;
			}
			int offset = (((daysSinceEpoch() %7) +7) %7);
			if (offset ==0 ){retval = "Thursday";}
			if (offset ==1 ){retval = "Friday";}
			if (offset ==2 ){retval = "Saturday";}
			if (offset ==3 ){retval = "Sunday";}
			if (offset ==4 ){retval = "Monday";}
			if (offset ==5 ){retval = "Tuesday";}
			if (offset ==6 ){retval = "Wednesday";}
			return retval;

		}
};
std::ostream& operator<<(std::ostream &strm, const Date &a) {
	  return strm << a.getY()<<"-"<<a.getM()<<"-"<<a.getD();
}

int main()
{

	Date test2 = {2019,5,5};

	std::cout<< "Nr of days since epoch is: "<<test2.daysSinceEpoch()<<std::endl;
	std::cout<<"Day of week is : "<<test2.dayOfWeek()<<std::endl;
	return 0;
}
