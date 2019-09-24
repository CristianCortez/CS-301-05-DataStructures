Semester::Semester() {
	cout << "obj built.";
}

void Semester::setNumP(int num) {
	numPrograms = num;
}
void Semester::setNumT(int num) {
	numTest = num;
}
void Semester::setNumF(int num) {
	numFinal = num;
}
void Semester::setWeigths(int num, int idx) {
	weights[idx] = num;
}

int Semester::getNumP(){
	return numPrograms;
}
int Semester::getNumT() {
	return numTest;
}
int Semester::getNumF() {
	return numFinal;
}
int Semester::getWeights(int idx) {
	return weights[idx];
}
