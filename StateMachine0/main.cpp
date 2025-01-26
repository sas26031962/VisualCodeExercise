#include <iostream>
#include <map>
#include <memory>
#include <functional>


template <typename State, typename Event>class StateMachine 
{
public:
  using TrnsitionFunction = std::function<State(State)>;

  using TransitionTable = std::map<std::pair<State, Event>, TransitionFunction>;
  StateMachine(State initialState) : currentState(initialState) {}

  void addTransition(State fromState, Event event, TransitionFunction transition) {
    transitionTable[{fromState, event}] = transition;
  }

  void handleEvent(Event event) {
    auto it = transitionTable.find({currentState, event});
    if (it != transitionTable.end()) {
      currentState = it->second(currentState);
      onStateChange();
    }
  }

  State getCurrentState() const { return currentState; }

  virtual void onStateChange(){};

protected:
  State currentState;
  TransitionTable transitionTable;

};//End of template <typename State, typename Event>class StateMachine 


enum class PlayerState {
  IDLE,
  WALKING,
  JUMPING
};

enum class PlayerEvent {
  WALK,
  STOP,
  JUMP
};

class PlayerStateMachine : public StateMachine<PlayerState, PlayerEvent> {
public:
    PlayerStateMachine(): StateMachine<PlayerState, PlayerEvent>(PlayerState::IDLE) {
        addTransition(PlayerState::IDLE, PlayerEvent::WALK, [this](PlayerState state){
             std::cout << "Start walking" << std::endl;
            return PlayerState::WALKING;
        });
        addTransition(PlayerState::WALKING, PlayerEvent::STOP, [this](PlayerState state){
            std::cout << "Stop walking" << std::endl;
           return PlayerState::IDLE;
         });
         addTransition(PlayerState::IDLE, PlayerEvent::JUMP, [this](PlayerState state){
              std::cout << "Start Jumping" << std::endl;
             return PlayerState::JUMPING;
         });
        addTransition(PlayerState::JUMPING, PlayerEvent::STOP, [this](PlayerState state){
            std::cout << "Stop Jumping" << std::endl;
           return PlayerState::IDLE;
        });
    }
    void onStateChange() override{
        std::cout << "Current State: " << static_cast<int>(getCurrentState()) << std::endl;
    }
};

int main() {
  PlayerStateMachine playerSM;
  playerSM.handleEvent(PlayerEvent::WALK);
  playerSM.handleEvent(PlayerEvent::JUMP);
  playerSM.handleEvent(PlayerEvent::STOP);
  playerSM.handleEvent(PlayerEvent::STOP);
    return 0;
}

 
