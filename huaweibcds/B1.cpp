#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct Team{
	int teamID;
	int winTimes;
	int lostTimes;
	int tieTimes;
	int score;
}Team;

int findTeam(int teamID,const vector<Team> &teams)
{
	for (int i=0;i<teams.size();++i)
	{
		if (teams[i].teamID==teamID)
		{
			return i;
		}
	}
	return -1;
}

void winCalc(Team &team)
{
	team.winTimes+=1;
	team.score+=3;
}

void lostCalc(Team &team)
{
	team.lostTimes+=1;
}

void tieCalc(Team &team)
{
	team.tieTimes+=1;
	team.score+=1;
}

int rank(int la1,const vector<Team> &teams)
{
	int rank=1;
	for (int i=0;i<teams.size();++i)
	{
		if (teams[la1].score<teams[i].score)
		{
			rank+=1;
		}
	}
	return rank;
}

bool cmp(const Team &a,const Team &b)
{
	return a.score>b.score;
}
int main()
{
	vector<Team> teams;
	
	string command;
	int teamID1,score1,teamID2,score2;
	int la1,la2;
	teams.clear();

	
		
		while(cin>>command)
		{
			if(command.compare("AddGameResult")!=0 && command.compare("GetTeamResult")!=0 && command.compare("Clear")!=0)
			{
				continue;
			}

		if (command.compare("AddGameResult")==0)
		{
			cin>>teamID1>>score1>>teamID2>>score2;
			la1=findTeam(teamID1,teams);
			if(la1==-1)
			{
				Team tmpTeam;
				tmpTeam.teamID=teamID1;
				tmpTeam.winTimes=0;
				tmpTeam.lostTimes=0;
				tmpTeam.tieTimes=0;
				tmpTeam.score=0;
				la1=teams.size();
				teams.push_back(tmpTeam);
			}

			la2=findTeam(teamID2,teams);
			if(la2==-1)
			{
				Team tmpTeam;
				tmpTeam.teamID=teamID2;
				tmpTeam.winTimes=0;
				tmpTeam.lostTimes=0;
				tmpTeam.tieTimes=0;
				tmpTeam.score=0;
				la2=teams.size();
				teams.push_back(tmpTeam);
			}
			if (score1>score2)
			{
				winCalc(teams[la1]);
				lostCalc(teams[la2]);				
			}else if(score1<score2) 
			{
				winCalc(teams[la2]);
				lostCalc(teams[la1]);
			}else
			{
				tieCalc(teams[la1]);
				tieCalc(teams[la2]);
			}
			//sort(teams.begin(),teams.end(),cmp);
		}else if(command.compare("GetTeamResult")==0){
			cin>>teamID1;
			la1=findTeam(teamID1,teams);
			if(la1==-1){
				cout<<teamID1<<" -1"<<endl;
				continue;
			}
			cout<<teamID1<<" "<<teams[la1].winTimes<<" "<<teams[la1].tieTimes<<" "<<teams[la1].lostTimes<<" "<<teams[la1].score<<" "<<rank(la1,teams)<<endl;

		}else if (command.compare("Clear")==0)
		{
			teams.clear();
		}
	}
	return 0;
}