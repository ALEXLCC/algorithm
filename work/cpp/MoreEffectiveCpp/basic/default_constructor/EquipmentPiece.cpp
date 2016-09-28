/*
 * 	item 4
 *	if not nessary , not supply a default constructor
 * */
#include<iostream>
using namespace std;
class EquipmentPiece{
	public:
		EquipmentPiece(int IDNumber);
	private:
		int IDNumber;
};
int main(){
	/*
	 *	error
	 *	EquipmentPiece bestPieces[10];	//cannot call constructors
	 *	no matching function EquipmentPiece() for call 
	 *	candidates are int , const &
	 *	EquipmentPiece *bestPieces=new EquipmentPiece[10];	//another problems
	 *
	 * */
	/*
	 *	solution 
	 *	use pointer array not object array
	 * */
	typedef EquipmentPiece * PEP;
	PEP bestPieces[10];
	/*
	 *	or PEP *bestPieces=new PEP[10];
	 * */
	for(int i=0;i<10;++i){
		bestPieces[i]=new EquipmentPiece(i+i+1);
	}
	/*
	 *	problems
	 *	need to delete all object to avoid resource leak
	 *	expensive memory for pointer object // first use raw memory and then placement new to construct the object
	 *	
	 *	void *rawMemory=operator new[] (10*sizeof(EquipmentPiece));
	 *	EquipmentPiece *bestPieces=static_cast<EquipmentPiece*>(rawMemory);
	 *	for(int i=0;i<10;++i){
	 *		new (&bestPieces[i])EquipmentPiece(id);
	 *	}
	 *	//manual destructor
	 *	for(int i=9;i>=0'--i){
	 *		bestPieces[i].~EquipmentPiece();
	 *	}
	 *	operatot delete[] (rawMemory);
	 *	//delete [] bestPieces  //not defined ,as bestPieces not create by new operator
	 * */
	return 0;
}
