using namepsace std;

struct studentData{
  int studentID;
  string first_name;
  string last_name;
  int exam1;
  int exam2;
  int exam3;
  int total;
  char ch;
}

void getTotal(studentData[]);
void getGrade(studentData[]);
void Lowest(studentData[],int d, int l, int[]);
void Highest(studentData[], int d, int l, int[]);
void getAverage(studentData[], int d, double l, double k, double[]);
void print(studentData[], int[]. int[], double[], double[]);
void sort(studentData[]);

int main(){
  studentData an[SIZE];
  int lowest1, lowest2, lowest3, lowest 4;
  int highest1; highest2, highest3, highest 4;
  double average1 = 0, average2 = 0, average3 = 0, average4 = 0;
  double average [info] = {};
  double standardDeviation[info] = {};
  
  openInputFile(inFile, int FileName);
  
  for (int count = 0; count < SIZE; count++){
    infile >> arr[count].studentID >> arr[count].first_name >> arr[count].last_name >> arr[count].exam1 >> arr[count].exam 2 >> arr[count].exam3;
   }
   
   infile.close();
   getTotal(arr);
   getGrade(arr);
   
   calcLowest(arr, lowest1, lowest2, lowest3, lowest4, lowest);
   calcHighest(arr, highest1, highest2, highest3, highest4, highest);
   
   getAverage(arr, SIZE, average1, average2, average3, average4, average);
   
   Cout << "In";
   
   print(arr, lowest, highest, average, standardDeviation);
  }
  voidgetGrade(studentData arr[]){
    for(i = 0; i < SIZE; i++)
      arr[i].ch = 'A';
     else if(arr[i].total >= 250)
      arr[i].ch = 'B';
     else if(arr[i].total >= 220)
      arr[i].ch = 'C';
     else if(arr[i].total >= 190)
      arr[i].ch = 'D';
     else
      arr[i].ch = 'F';
  }

  void sort(studentData arr[]){
    studentData temp;
    for(int i = 0; i < (SIZE - 1); i++){
      for(int j = i + 1; j < SIZE; j++){
        if(arr[i].last_name > arr[j].last_name){
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }   
      }
    }
  }
