#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>
#include <iostream>
#include<fstream>
using namespace sf;
using namespace std;
int main()
{	float touchscale = sf::VideoMode::getDesktopMode().height * 1.f / 1080;
	float aspect = sf::VideoMode::getDesktopMode().width * 1.f / sf::VideoMode::getDesktopMode().height;
	const int width = (int)(1080 * aspect);
	sf::RenderWindow window(sf::VideoMode(50, 100, 32), "SFML Mirror",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
 
           

    
 
    
    
    
	float t =0,p=0,i=3,j=3,m=0.5,n=0,a,b;
bool  lost = false,ballmove= false;
int score = 0, highscore=0,s=3;	
ifstream sc;
sc.open("score.html");
sc>>highscore;
sc.close();
//sc>>highscore;

	sf::RectangleShape rec, gameover,rec2,back;
	   gameover.setSize(sf::Vector2f(50,50));
	gameover.setPosition(0,50);
	gameover.setOutlineThickness(0.3);
	gameover.setFillColor(sf::Color::Black);
	gameover.setOutlineColor(sf::Color::Black);
	gameover.setOrigin(0,0);
	
	rec.setSize(sf::Vector2f(5,12));
	rec.setPosition(43,40);
	rec.setOutlineThickness(0.3);
	rec.setFillColor(sf::Color::White);
	rec.setOutlineColor(sf::Color::Red);
	rec.setOrigin(0,0);
	
	back.setSize(sf::Vector2f(25,100));
	back.setPosition(0,0);
	back.setOutlineThickness(0.3);
	back.setFillColor(sf::Color::White);
	back.setOutlineColor(sf::Color::Red);
	back.setOrigin(0,0);
	
	rec2.setSize(sf::Vector2f(5,12));
	rec2.setPosition(2,40);
	rec2.setOutlineThickness(0.3);
	rec2.setFillColor(sf::Color::Black);
	rec2.setOutlineColor(sf::Color::Red);
	rec2.setOrigin(0,0);
	
	sf::CircleShape ball ;
	ball.setRadius(0.5);
	ball.setPosition(20,40);
	ball.setOutlineThickness(0.3);
	ball.setFillColor(sf::Color::Red);
	ball.setOutlineColor(sf::Color::Red);
	ball.setOrigin(0,0);
	float y = 40;
	    sf:: Font font;
    font.loadFromFile("GameAssets/Fonts/OpenSans-ExtraBold.ttf");
        
	while (window.isOpen())
    {	//ball.move(0.03,0.03);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {ball.setPosition(20,40);
                window.close();}
        if(sf::Touch::isDown(0))
            {
            sf::Vector2i	relativePos = sf::Touch::getPosition(0,window);
        // if((relativePos.y)/130>=4&&(relativePos.y)/130<=8)
        if(lost)
        { if(relativePos.x>5&&relativePos.x<400)
    {    if(relativePos.y>50&&relativePos.y<150)
        lost=false;}}
        //if(relativePos.x >290)
        if(!lost)
{ /*if((relativePos.y)/130>t)
                  {
                     rec.move(0.f,i);
                rec2.move(0.f,i);
                 //   i=i+0.1;;
                 
                    // if(i>9)
                     i=10.5;
                       }
          if((relativePos.y)/130<t)
       {  rec.move(0.f,-j);
       rec2.move(0.f,-j);
      // j=j+0.1;
     //  if(j>9)
       j=10.5;
       }
            
            t =( relativePos.y)/130;*/
            rec.setPosition(rec.getPosition().x,relativePos.y/15);
                rec2.setPosition(rec2.getPosition().x,relativePos.y/15);
            
      if(relativePos.x>270&&relativePos.x<350)
    {    if(relativePos.y>470&&relativePos.y<540)
       {
       	ballmove= true;
       }
       	
       }
     /*  if(relativePos.x <290)
       { if((relativePos.y)/130>p)
                  {
                     rec2.move(0.f,i);
                
                 //   i=i+0.1;
                 
                    // if(i>9)
                     i=9;
                       }
          if((relativePos.y)/130<p)
       {  rec2.move(0.f,-j);
      // j=j+0.1;
     //  if(j>9)
       j=9;
       }
            
            p =( relativePos.y)/130;
       }
       
            */       	//ball.move(0.3,0.3);
            }
            }
                  	            //	ball.move(0.3,0.3);	            	                   
        }
        	//ball.move(0.3,0.3);
        	a=ball.getPosition().x;
        	b=ball.getPosition().y;
        	if(ballmove)
        	ball.move(m,n);
        window.clear();

    /*if(ball.getPosition().x<=2)    	    
 {   m=0.5;
 if(ball.getPosition().y<b)
    n = rand()%-4-4;  
    else
    n = rand()% 7 +1;
    n=n/10;}*/
     if(ball.getPosition().y<=0)  
     {if(ball.getPosition().x>a)
     	m = rand()%7 +1;
     	else
     	m =rand()%-4 -4;
     	m=m/10;
     n= 0.5;
     }
      if(ball.getPosition().y>=100)  
      {if(ball.getPosition().x<a)
      	m = rand()%-4-4;
      	else
      	m = rand()% 7+1;
      	m=m/10;
      n= -0.5;
      }
     if(ball.getPosition().x>=37 && ball.getPosition().x<=50)
      {
      	if(ball.getPosition().y>=rec.getPosition().y&&ball.getPosition().y<=rec.getPosition().y + 12)
     {  /*sf::Text pauseMessage;
   pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(24);	
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to SFML pong!\nTouch screen to start the game");
    window.draw(pauseMessage);*/
    score ++;
     	m=-0.5;
  if(ball.getPosition().y>b)
  n= rand()% 4+ 1;
  else
  n= rand()% -2 -2;
  n=n/10; 
     }
      	
      }
       if(ball.getPosition().x>=0 && ball.getPosition().x<=6)
      {
      	if(ball.getPosition().y>=rec2.getPosition().y&&ball.getPosition().y<=rec2.getPosition().y + 12)
     {  
     score ++;
     m=0.5;
 if(ball.getPosition().y<b)
    n = rand()%-2-2;  
    else
    n = rand()% 4+1;
    n=n/10;
     }
      }
   if(ballmove)   
  ball.move(m,n);
  if(!lost)
{window.draw(back);
	window.draw(rec);
window.draw(rec2);
}
  if(ball.getPosition().x>=50||ball.getPosition().x<=0)
  {lost = true;
m=0.5;
n = 0;
  rec.setPosition(43,40);
  rec2.setPosition(2,40);
      }if(lost)
  {ballmove = false;
  		window.draw(gameover);
  		std::stringstream ss1;
  		ss1<<highscore;
  		std::string high(ss1.str());
  	sf::Text pauseMessage,highs,scor;
    highs.setFont(font);
    highs.setCharacterSize(10);
    highs.setFillColor(sf::Color::White);
    highs.setPosition(20, 85);
    scor.setFont(font);
    scor.setCharacterSize(14);
    scor.setFillColor(sf::Color::White);
    scor.setPosition(4, 50);
   pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(9);	scor.setString("High\nScore");
    pauseMessage.setFillColor(sf::Color::Black);
    pauseMessage.setString(
 "Start\nGame By\nHarsh Jain\n");
 highs.setString(high);
 //pauseMessage.setString(high);
   
    	sf::FloatRect pauseRect = pauseMessage.getLocalBounds();	
	pauseMessage.setOrigin(6,9);
    pauseMessage.setPosition(4.5, 10);
  //  window.draw(pauseMessage);
    ball.setPosition(20,40);
  	/*m=-0.5;
  if(ball.getPosition().y>b)
  n= rand()% 7+ 1;
  else
  n= rand()% -4 -4;
  n=n/10;*/
  sf::Texture img;
img.loadFromFile("Sen/Har5.jpg",sf::IntRect(0,0,50,50));

sf::Sprite imgsprite;
imgsprite.setTexture(img);

window.draw(imgsprite);
window.draw(highs);
window.draw(scor);
window.draw(pauseMessage);

if(score> highscore)
highscore =score;
score =0;
  }
  if(!lost)
{  sf::Text points;
  points.setFont(font);
   	std:: stringstream ss;
  	ss<<score;
  	std::string mess = ss.str();
  	points.setString(mess);
  	 points.setCharacterSize(7.5);
    	sf::FloatRect pointsrec = points.getLocalBounds();	
	points.setOrigin(6,9);
  	points.setPosition(40,20);
window.draw(ball);	
window.draw(points);

/*  if(ball.getPosition().x<=2) 
  {if(ball.getPosition().y<b)
  {m = (rand()% -3);
   ball.move(-0.5,m);}
  else
 { m= rand()% 3;
   ball.move(m,m);}
 } */
}
	window.display();
	
 ifstream st;
    st.open("score.html");
    	st>>s;
	
	st.close();
	if(highscore>s)
	{
	
		ofstream st;
	st.open("score.html");
	st<<highscore;
	st.close();
	
	}
	//y=y+0.01;
    }
   
    
   // y=40;
	return 0;
}