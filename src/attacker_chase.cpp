#include "attacker_chase.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/a_star3d.hpp>


#include <cstdlib>

using namespace godot;

AttackerChase::AttackerChase() {}

AttackerChase::~AttackerChase() {}

void AttackerChase::_ready() {
    if(Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    attacker = Object::cast_to<Attacker>(this->get_parent()->get_parent());
    player = get_node<Player>("../../../Player");
    a_star = memnew(AStar3D);
    raycast = get_node<Raycast>("../../Raycast");
}

void AttackerChase::enter() {
    UtilityFunctions::print("enter attacker chase state");
}

void AttackerChase::update(double delta) {
    if(Engine::get_singleton()->is_editor_hint()) {
        return;
    }
}

void AttackerChase::physics_update(double delta) {
    if(Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    if (raycast->is_colliding() && raycast->get_collider() == player) {
        attacker->set_position(Vector3(0, 10, 0));
    } else {
        Vector3 dest = player->get_position();
        Vector3 dir = dest - attacker->get_position();
        dir.normalize();
        attacker->set_velocity(dir * 500 * delta);
        attacker->move_and_slide();
        attacker->set_position(attacker->get_position());
        if ((dest - attacker->get_position()).length() < 11) {
            emit_signal("transitioned", "attackerchase", "attackerattack");
        }
    }
}

void AttackerChase::exit() {
    UtilityFunctions::print("exit attacker chase state");
}