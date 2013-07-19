#include<sound_play/sound_play.h>
#include<ros/ros.h>
#include<unistd.h>
#include<std_msgs/String.h>

const char* left="left";
const char* right="right";
const char* forward="forward";
const char* back="back";
const char* halt="stop";
void callback(const std_msgs::String::ConstPtr& msg)
{
const char* text;
sound_play::SoundClient sc;	
sc.say("hi","voice_don_diphone");
text=msg->data.c_str();
if(strcmp(text,left)==0)
{
	sc.say("Rotating Left","voice_don_diphone");
}
if(strcmp(text,right)==0)
{
	sc.say("Rotating right","voice_don_diphone");
}
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"rover_voice");
	ros::NodeHandle n;
	sound_play::SoundClient ss;
	ss.say("hel","voice_don_diphone");
	ros::Subscriber voice=n.subscribe("/navCommands/output",1000,callback);
	ros::spin();
	return 0;
}


