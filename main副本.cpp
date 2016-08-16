//
//  main.cpp
//  投票系统
//
//  Created by neworigin on 16/8/8.
//  Copyright © 2016年 neworigin. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "Voter.hpp"
#include "Candidate.hpp"
#include "PersonSet.hpp"
int main(int argc, const char * argv[]) {

    
    Voter *v1 = new Voter("John", 20, 6000,1);
    Voter *v2 = new Voter("Frank", 26, 3000,2);
    Voter *v3 = new Voter("Anna", 20, 9600,1);
    Voter *v4 = new Voter("James", 67, 9600,2);
    Voter *v5 = new Voter("Jane", 40,  5600,3);

    

    Candidate *c1 = new Candidate("Henry", 22,9000 );
    Candidate *c2 = new Candidate("Cindy", 23,9600);
    Candidate *c3 = new Candidate("Chailie", 25,8600);

    
    //产生一个随机数的种子。
    srand((int)time( NULL ) );
    
    PersonSet voters;
    voters.Add(*v1);
    voters.Add(*v2);
    voters.Add(*v3);
    voters.Add(*v4);
    voters.Add(*v5);

    
    PersonSet candidates;
    candidates.Add(*c1);
    candidates.Add(*c2);
    candidates.Add(*c3);

    
    int numVoters = voters.Size();
    voters.Reset();
    cout<<"~~~~~~~~~~~~~~~~~~投票人名单~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout << "Number of voters = " << numVoters << "\n";
    for(int i = 0; i<numVoters; i++)
    {
        Voter& voter = static_cast<Voter&>(voters.NextElement());
        cout << voter <<endl;
    }
  
    cout<<"~~~~~~~~~~~~~~~~~~候选人名单~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    candidates.print();
    voters.Reset();
    cout<<endl;

    cout<<"正在投票...请稍后 \n";cout<<endl;
    
    
    for(int i = 0; i<numVoters; i++)
    {
        Voter& v = static_cast<Voter&>(voters.NextElement());

        /*choose a candidate*/
        Candidate& chosenCandidate = static_cast<Candidate &>
         (v.SelectCandidate(candidates));
          v.Vote(chosenCandidate);
    }


     /*检测是否所有投票人都投票了*/

    if (voters.Size() != Voter::Voters())
    {
        cout<<"Not all voers voted !!!!"<<endl;
        
    } else
    {
        cout<<"Success: 100% voted" <<endl ;
    }

  
   
    /*选出获胜者为领导*/
   
    Candidate* winner = static_cast<Candidate*>(&candidates[0]);
    for ( int i=0; i<candidates.Size(); i++ )
    {
        if ( *winner < *(static_cast<Candidate*>(&candidates[i]) ))
        {
            
            winner = static_cast<Candidate*>(&candidates[i]); }
        }

   
    /*打印候选人票数*/
    for(int i = 0; i<candidates.Size(); i++)
    {
        Candidate& can = static_cast< Candidate&>(candidates.NextElement());
        cout<<"候选人: "<<can.getName()<<"\t票数: "<< can.GetVotesNum()<<endl;
    }
    
    /*二次投票*/
    PersonSet Winner;
    candidates.Reset();
    int VotersNumOfwinner=winner->GetVotesNum();                                         //获胜者的票数
    
    for (int i=0; i<candidates.Size(); i++)
        {
            int VotesNumOfOther=static_cast<Candidate*>(&candidates[i])->GetVotesNum();  //其他候选人的票数
            
            if (VotersNumOfwinner==VotesNumOfOther)
            {
                Winner.Add(candidates[i]);
            }
    
        }
    
    if (Winner.Size()>=2)
    {
     
      cout<<"~~~~~~~~~~~~~~~~存在同时胜出情况~~~~~~~~~~~~~~~~"<<endl<<endl;
      cout<<"进行第二次投票......."<<endl;
    
    
    /*投票*/
    for(int i = 0; i<numVoters; i++)
    {
        Voter& v1 = static_cast<Voter&>(voters.NextElement());
        Candidate& chosenCandidate = static_cast<Candidate &>
        (v1.SelectCandidate(Winner));
         v1.Vote(chosenCandidate);
    }

    Candidate* winner = static_cast<Candidate*>(&Winner[0]);
    for ( int i=0; i<Winner.Size(); i++ )
    {
        if ( *winner < *(static_cast<Candidate*>(&Winner[i]) ))
        {
            
            winner = static_cast<Candidate*>(&Winner[i]);
        }
    }
    
    
    /*打印候选人票数*/
    for(int i = 0; i<Winner.Size(); i++)
    {
        Candidate& c = static_cast< Candidate&>(Winner.NextElement());
        cout<<"候选人: "<<c.getName()<<"\t票数: "<< c.GetVotesNum()<<endl;
    
    }
        
    }
    cout <<"The Final winner is: "<< *winner;
    cout<<"所有给候选人投票的人平均薪水和平均年龄: "<<"("<<winner->GetAverageVoterSalary()
    <<","<<winner->GetAverageVoterAge()<<")"<<endl;
    
    

    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete c1;
    delete c2;
    delete c3;

    return 0;
    
    
    }
