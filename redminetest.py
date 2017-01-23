import getpass
from datetime import date
from datetime import timedelta
import pprint
from redmine import Redmine

#user = raw_input("Redmine user: ")
#psw = getpass.getpass()

user = ""
pwd = ""

#credentials = {}
with open('Usernames.txt', 'r') as f:
	user, pwd = f.readline().strip().split(':')
    #for line in f:
    #    user, pwd = line.strip().split(':')
        #credentials[user] = pwd

IssStatus = {\
"0" : "0",
"1" : "New",
"2" : "In Progress",
"3" : "Resolved",
"4" : "Feedback",
"5" : "Closed", 
"6" : "Rejected", 
"7" : "Review",
"8" : "Blocked"} 

weeklyComments = [{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, \
{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, \
{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, \
{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, \
{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, \
{}, {}, {}, {}, {} ]

issueStates = {}

prevstate = None

def commentFreq(issue):
	commentCount = 0
	for week, item in enumerate(weeklyComments):
		weeklyComments[week][issue.id] = 0
	for j in issue.journals:
		if getattr(j, "notes", None):
			notes = getattr(j, 'notes', None)
			createdOn = getattr(j, 'created_on', None).date()
			weekNum = createdOn.isocalendar()[1]
			weeklyComments[weekNum][issue.id] = weeklyComments[weekNum][issue.id] + 1

def issueStatesFill(issue):
	for j in issue.journals:
		for detail in getattr(j,'details', None):
			if detail.get('name', None) == 'status_id':
				oldState =  IssStatus.get(detail.get('old_value', None), None) 
				currState = IssStatus.get(detail.get('new_value', None), None)
				createdOn = getattr(j, 'created_on', None).date()
				if issueStates.get(issue.id, None):
					issueStates[issue.id].append({oldState:createdOn})
				else:
					issueStates[issue.id] = [{oldState:createdOn}]

def issueInProgressInWeek(issue, weeknum):
	inProgressCount = 0
	userDic = {}
	global prevstate
	if not issueStates.get(issue.id, None):
		return
	for item in issueStates[issue.id]:
		for state, date in item.iteritems():
			print "Curr state = " + str(state) + "\tPrev State = " +  str(prevstate) + "\tdate = " + str(date)
			pass
		if state == "In Progress" and date.isocalendar()[1] <= weeknum:
			prevstate = "In Progress"
			prevDateInProgress = date
		else:
			if prevstate == "In Progress" and date.isocalendar()[1] > weeknum:
				print "Prev state in progress, cur week is %s and status change on %s" % (weeknum, date.isocalendar()[1])
				#prevdate on prev weeks, date on next weeks
				daysInProgressThisWeek = 7
				inProgressCount = inProgressCount + 1
				userDic[issue.assigned_to.name] = inProgressCount
			if prevstate == "In Progress" and date.isocalendar()[1] == weeknum:
				#prevdate on prev weeks, date on current week
				#beginofweek = date - timedelta(days=date.weekday())
				daysInProgressThisWeek = timedelta(days=date.weekday()).days
				inProgressCount = inProgressCount + 1
                                userDic[issue.assigned_to.name] = inProgressCount
	print userDic
	
redmine = Redmine('https://redmine.ma.merann.ru', requests={'verify': False}, username=user, password=pwd)

#for iss in redmine.issue.all(project_id='cruise-america', status_id='*'):
iss = redmine.issue.get(1900, include='children,journals,watchers')
issueStatesFill(iss)
for week in range(20):
	#print "Week#|	Assigned to|	Issue#|	Issue state|	Date created on"
	print "WEEK # %s" % (week)
	#print assigned_to.name
	#print issue.id
	#print "In Progress"
	#print createdOn
	issueInProgressInWeek(iss, week)
print dir(iss)


#commentFreq(iss)
#pprint.pprint(weeklyComments)
#pprint.pprint(issueStates)



                        

