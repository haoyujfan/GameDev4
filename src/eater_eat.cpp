#include "eater_eat.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <cstdlib>

using namespace godot;

EaterEat::EaterEat() {}

EaterEat::~EaterEat() {}

void EaterEat::_ready() {
    if(Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    eater = get_node<Eater>("../../../Eater");
}

void EaterEat::enter() {
    UtilityFunctions::print("enter eat state");
}

void EaterEat::update(double delta) {
    if (eater) {
        eater->set_velocity(Vector3(0, 10, 0));
        emit_signal("transitioned", "EaterEat", "EaterRetreat");
    }
}

void EaterEat::physics_update(double delta) {

}

void EaterEat::exit() {
    UtilityFunctions::print("exit eat state");
}