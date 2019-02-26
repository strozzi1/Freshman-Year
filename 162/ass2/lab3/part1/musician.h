#include <string>

using namespace std;

class musician{
	private:
		string name;
	public:
		name(string);
		string get_name() const;
		void set_name(const string &);

};
