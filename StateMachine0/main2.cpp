#include <iostream>
#include <map>
#include <functional>

enum class State {
    OFF,
    ON,
    PAUSED
};

enum class Event {
    POWER,
    PLAY,
    STOP
};

using TransitionFunction = std::function<State(State)>;
using TransitionTable = std::map<std::pair<State, Event>, TransitionFunction>;

class StateMachine {
public:
  StateMachine(State initialState) : currentState(initialState) {
      transitionTable[{State::OFF, Event::POWER}] = [this](State state){
        std::cout << "Turning ON" << std::endl;
         return State::ON;
      };
      transitionTable[{State::ON, Event::POWER}] = [this](State state){
        std::cout << "Turning OFF" << std::endl;
         return State::OFF;
      };
      transitionTable[{State::ON, Event::PLAY}] = [this](State state){
        std::cout << "Paused" << std::endl;
        return State::PAUSED;
      };
      transitionTable[{State::PAUSED, Event::PLAY}] = [this](State state){
         std::cout << "Playing" << std::endl;
        return State::ON;
      };
       transitionTable[{State::PAUSED, Event::STOP}] = [this](State state){
        std::cout << "Turning OFF from paused" << std::endl;
        return State::OFF;
      };
  }


  void handleEvent(Event event) {
        auto it = transitionTable.find({currentState, event});
        if(it != transitionTable.end()){
            currentState = it->second(currentState);
        }
  }
  State getCurrentState() const {
    return currentState;
  }

private:
    State currentState;
    TransitionTable transitionTable;
};


int main() {
  StateMachine sm(State::OFF);

  sm.handleEvent(Event::POWER);
  sm.handleEvent(Event::PLAY);
  sm.handleEvent(Event::STOP);
  sm.handleEvent(Event::POWER);


    return 0;
}
