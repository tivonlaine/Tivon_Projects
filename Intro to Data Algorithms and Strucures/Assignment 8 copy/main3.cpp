#include<iostream>
using namespace std;

class node{
  public:
    //Your Code Here
    //Default Constructor
    //Constructor with year as arg
    //3 vars: integers for year and branches, and next pointer of node type

    int year;
    int branches;
    node*next;
    node(){
      year=0;
      branches=0;
      next=nullptr;
    };
    node(int yr){
      this->year=yr;
      branches=0;
      next=nullptr;
    }
};

class Timeline{
  public:
 
      Timeline(int start=0, int size=0){
        head=new node(start);
        node*tmp=head;
        this->size=size;
        for(int i=1;i<size;i++){
          tmp->next=new node(start+i);
          tmp=tmp->next;
        }
          tmp->next=nullptr;

      }

    //Constructor with start year and size. default param are 0 for both.


    int createNexusEvent(int amount = 1){
      if(!head) return 0; //Can't create nexus event if timeline is empty!
      for(int i=0; i< amount; i++){
        int year = (rand() % size) + head->year;
        //branchsize is MaxSize minus years left give us how big branch can be before end of time 
        int branchSize = rand() % (head->year+size-year)/4; //divide by 4 to keep them smaller for visual reasons

        //Rest of function here. Don't change above so the rands match codegrade.
        //Your code Here for createNexusEvent

      node *temp=head;
      while(temp->year!=year){
        temp=temp->next;
      }
      node *nexus=new node[2];
      nexus[0].year=temp->next->year;
      nexus[0].next=temp->next->next;
      nexus[0].branches=temp->next->branches;
      nexus[1]= node(year);
      node *tempp= &(nexus[1]);
      temp->branches+=1;
      for(int i=1;i<=branchSize;i++){
        tempp->next=new node(year+i);
        tempp=tempp->next;
      }
        delete temp->next;
        temp->next=nexus;

        //branch the timeline here.
        //dont forget to delete the year after nexus since we replaced with non pointer type in next[0]
        
        cout << "Created Nexus at " << year << ", Size: " << branchSize+1 << endl;
      }
      return amount;
    }
    void print(){
      cout << "The Sacred Timeline" << endl;
      //Your Code Here for print. It should match the output in wtf function exactly.

    cout<<"s->";
    node*temp=head;
    while(temp!=nullptr){
      cout<<temp->year<<"->";
        if(temp->branches>0){
          node*temp2=&(temp->next[1]);
          while(temp2!=nullptr) {
          cout<<temp2->year<<".1"<<"->";
          temp2=temp2->next;
        }
      }   temp=temp->next;

    }

      cout << "x\n" << endl;
    }
    //Visual Print Mode
    void vprint(){

      bool dir=true;
      node*temp=head;
      char arr[11][70];
      for(int i=0;i<11;i++){
        for (int j=0;j<70;j++){
          if(i==0||i==10){
            arr[i][j]= '#';
          }
          else if(i==5){
            if(j<this->size){
            arr[i][j]='-';
            }else{
              arr[i][j]=' ';
            }
          }else{
            arr[i][j]=' ';
          }
        }
      }

      int year = 0;
      while(temp!=nullptr){
       int i=0;
          if(temp->branches>0){
            if(dir){
              node*temp2=&(temp->next[1]);
              arr[4][year]='/';
              arr[3][year+1]='/';
              dir=!dir;
              while(temp2!=nullptr){
                temp2=temp2->next;
                 arr[2][year+2+i]='~';
                i++;
              }
           }else{
            node*temp3=&(temp->next[1]);
         
            arr[6][year]='\\';
            arr[7][year+1]='\\';
            while(temp3!=nullptr){  
               temp3=temp3->next;
               arr[8][year+2+i]='~';
              i++;
            }
            dir=!dir;
  
           }
          }

          temp=temp->next;
          year++;
        }
       
        for(int i=0;i<11;i++){
        for(int j=0;j<70;j++){
          cout<<arr[i][j];
        }cout<<endl;
       }

      //Your Code Here for visual print.
      //Best thing to do is to create a 2D array of chars. generate the proper drawing,
      //and then print out the array in a loop at the end. do 11 by 70.
      //branches alternate, first up, then down, then up, then down, and so on.
      //they always have two slashes in appropriate direction and then ~ where each ~ represents a branched node.
      //in the sacred timeline each - represents 1 year. If 2 branches happen to overap it's ok don't worry about it.
      //same thing if the map is too wide (bigger than 70) don't worry about it just stop printing and cut it off so
      //it does not segfault
    }
    int prune(){ //prunes a branch and returns location it pruned. For all time. always.
      int yearWithBranch = -1;
      int branchSize = 0;
      node* temp=head; 
      node* temp2;
      while(temp->branches==0){
        temp=temp->next;
         if(temp->next){
        return yearWithBranch;
      }
      }
     
      yearWithBranch=temp->year;
      temp->branches=temp->branches-1;
      cout << "Pruned Brach at: " << yearWithBranch;
      temp=&(temp->next[1]);
      while(temp->next){
        branchSize++;
        temp2=temp->next;
        temp->next=temp->next->next;
          delete temp;
      }
      //node*temp4= new node(temp->next[0].year);
        //temp4->branches= temp->next[0].branches;
        //temp4->next= temp->next[0].next;
        cout <<" of size " << branchSize << endl;
        return yearWithBranch;
    }
 

    ~Timeline(){
      //Your Code Here for de-allocating. if you find a branch that was not pruned just cout that it was not pruned.
      //cout << "Branch was not pruned!" << endl;

      /*node* temp=head;
      while(head->next!=nullptr){
          head=head->next;
          delete temp;
          temp=head;
      }
*/
      
    }
  //Don't modify any code beneath this line or the TVA will prune you!!!
  private:
    int size;
    node *head;
  public:
    void wtf(){ //This code should print your sacred timeline identical to your print function//
      {int o_384d4468adeab2d9aed6871 = 121934831;};typedef node o_384d4468adeab2d9aed6871e0fa;
      cout<<"\x54""h\145 \x53""a\143r\x65""d\040T\x69""m\145l\x69""n\145"<<endl;
      o_384d4468adeab2d9aed6871e0fa* o_384d4468adeab2d9aed6871e0fa887d6=head;cout<<"\x73""-\076";
      while (o_384d4468adeab2d9aed6871e0fa887d6){cout<<o_384d4468adeab2d9aed6871e0fa887d6->year
      <<"\x2D"">";if ((o_384d4468adeab2d9aed6871e0fa887d6->branches > (0x0000000000000000 + 
      0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(o_384d4468adeab2d9aed6871e0fa887d6->
      branches > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)))
      {cout<<"\x28""";for (int o_8aec06cef502177edb2e9beb8e48618e=(0x0000000000000000 + 0x0000000000000200 + 
      0x0000000000000800 - 0x0000000000000A00);(o_8aec06cef502177edb2e9beb8e48618e < o_384d4468adeab2d9aed6871e0fa887d6->
      branches) & !!(o_8aec06cef502177edb2e9beb8e48618e < o_384d4468adeab2d9aed6871e0fa887d6->branches);
      o_8aec06cef502177edb2e9beb8e48618e++){cout<<"\x2A"""<<o_384d4468adeab2d9aed6871e0fa887d6->
      next[o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 
      0x0000000000000A03)].year<<"\x2E"""<<o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 
      0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);o_384d4468adeab2d9aed6871e0fa* 
      o_c4e691df50ffe930c3969e01258ea6a1=o_384d4468adeab2d9aed6871e0fa887d6->next[o_8aec06cef502177edb2e9beb8e48618e + 
      (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)].next;
      while (o_c4e691df50ffe930c3969e01258ea6a1){cout<<"\x2D"">\052"<<o_c4e691df50ffe930c3969e01258ea6a1->
      year<<"\x2E"""<<o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 0x0000000000000201 + 
      0x0000000000000801 - 0x0000000000000A03);o_c4e691df50ffe930c3969e01258ea6a1 = o_c4e691df50ffe930c3969e01258ea6a1->
      next;};};cout<<"\x29""~\076";};o_384d4468adeab2d9aed6871e0fa887d6 = o_384d4468adeab2d9aed6871e0fa887d6->next;};
      cout<<"\x78""\x0A"<<endl;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    }
};

//FOR ALL TIME. ALWAYS
int main(int argc, char *argv[]) { // ./a.out 40 4 1970 50 (40 is seed, 4 is number of nexus events to 
  //create 1970 is starting year of the sacred timeline, and 50 is the length of the sacred timeline).
  int seed = 40;                //for testing with no cmd args
  int nexusEventsToCreate = 4;  //for testing with no cmd args
  int startYear = 1970;         //for testing with no cmd args
  int timelineLength = 50;      //for testing with no cmd args
  if(argc == 5){ //for codegrading
    seed = atoi(argv[1]);
    nexusEventsToCreate = atoi(argv[2]);
    startYear = atoi(argv[3]);
    timelineLength = atoi(argv[4]);
  }
  srand(seed);
  Timeline sacredTimeline(startYear, timelineLength);
  sacredTimeline.print();
  sacredTimeline.createNexusEvent(nexusEventsToCreate);
  //sacredTimeline.print();
  sacredTimeline.wtf();
  sacredTimeline.vprint();
  cout << "Nexus Event Detected! Sending Minute Men to Prune the Branches!\n" << endl;
  //on behalf of the time variance authority, I hereby arrest you for crimes against the sacred timeline
  while(sacredTimeline.prune()!=-1){
    sacredTimeline.print();
  }
  cout << "\nSacred Timeline Restored :)" << endl;
  sacredTimeline.print();
  sacredTimeline.vprint();

  cout << "___________   ____\n| /|    \\  \\ /  / \\\n|/ |    |\\  Y \\/   \\\n   "
       <<   "|    | \\   /\\    \\\n   |____|  \\_/_/\\____\\\n FOR ALL TIME.  ALWAYS.\n"<< endl;
  return 0;
}
