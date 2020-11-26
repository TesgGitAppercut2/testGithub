#include <iostream>
#include <exception>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;

string output(const string& name, const string& value)
{
	return name + " -&gt; " + value;
}

int main()
{
	try
	{
		Cgicc cgi;
		cout << HTTPHTMLHeader() << endl;
		cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;
		cout << html().set("lang", "EN").set("dir", "LTR") << endl;
		cout << html() << head() << title("Test Case: XSS/Basic") << head() << endl;
		cout << body().set("bgcolor","#cccccc") << endl;
		cout << h1("Test Case: XSS/Basic") << endl;
		const_form_iterator iter;
		for(iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) {
			cout << output(iter->getName(),iter->getValue()) << endl;;
		}
		cout << body() << html();
	}
	catch(const exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	return 0;	
}
