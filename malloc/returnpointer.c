char* get_string(){
	char* s="welcome";
	*s='p';
	return s;
}
main(){
	char* p=get_string();
	printf("%s\n",p);
}
