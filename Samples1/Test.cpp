#include<iostream>
#include<string>

using namespace std;

class imotion
{
	public:
	 virtual void speed()=0; 	
	 virtual void acceleration()=0;
	 virtual void distance()=0; 	
};



class vehicle:public imotion{
	public:
	virtual void speedup()=0; 	
	virtual void logperfomance()=0;
	virtual void safelandingdistane()=0; 
};


class fighterjet:public vehicle{
	private:
		float _acceleration;
		float gravitationalforce;
		string fuel;
	public:
		
	fighterjet():_acceleration(500),gravitationalforce(9.5),fuel("high"){}
	void speedup(){
	cout<<"[FighterJet] Afterburners engaged!"<<"Accleration: "<<_acceleration<<"m/s^2"<<endl;	
	}
	void logperfomance()
	{
		cout<<"[FighterJet] G-Force: "<<gravitationalforce<<"| fuel burning rate: "<<fuel<<endl;
	}
	void safelandingdistane()
	{
		cout<< "Safe Landing Distance: 1250 meters"<<endl;
	}
	
    // Empty implementations (not needed for this output)
    void speed() {}
    void acceleration() {}
    void distance() {}
};

class cargoplane:public vehicle{
	float weight;
	string altitude;
	float _acceleration;
	public:
		cargoplane():weight(2000),altitude("stable"),_acceleration(50){}
	void speedup()
	{
		cout<<"[CargoPlane] Cargo Weight: "<<weight<<"kg | Altitude: "<<altitude<<endl;
	}
	void logperfomance()
	{
		cout<<"[CargoPlane] Throttle increased. Acceleration: "<<_acceleration<<"m\s^2"<<endl;
	}
	void Weight()
	{
		cout<<"[CargoPlane] Cargo Weight: "<<weight<<"kg | Altitude: "<<altitude<<endl;
	}
	void safelandingdistane()
	{
		cout<<"Safe Landing Distance: 250 meters"<<endl;
	}
		
    // Empty implementations (not needed for this output)
    void speed() {}
    void acceleration() {}
    void distance() {}
};
int main()
{
	fighterjet f;
	f.speedup();
	f.logperfomance();
	f.safelandingdistane();
	
	cargoplane c;
	c.speedup();
	c.logperfomance();
	c.Weight();
	c.safelandingdistane();
}
