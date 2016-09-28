#include<iostream>
using namespace std;
class NLComponent{
	public:
		virtual NLComponent* clone() const=0;
};
class TextBlock:public NLComponent{
	public:
		virtual NLComponent* clone() const{
			return new TextBlock(*this);
		}
};
class Graphic:public NLComponent{
	public:
		virtual NLComponent* clone() const{
			return new Graphic(*this);
		}
};
class NewsLetter{
	public:
		NewsLetter(const NewsLetter& rhs);
	private:
		List<NLComponent*>components;
};
NewsLetter::NewsLetter(const NewsLetter& rhs){
	for(list<NLComponent*>::const_iterator it=rhs.components.begin();it!=rhs.components.end();++it){
		components.push_back((*it)->clone());
	}
}
