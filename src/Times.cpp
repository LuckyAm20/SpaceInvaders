#include "Times.h"

Times::Times()
{
    times = sf::Time::Zero;
    p_shoot = sf::Time::Zero;
    inv_shoot = sf::Time::Zero;
    sup = sf::seconds(1.f / 60.f);
}

sf::Time Times::get_times()
{
    return times;
}

sf::Time Times::get_sup()
{
    return sup;
}

sf::Time Times::get_p_shoot()
{
    return p_shoot;
}

sf::Time Times::get_inv_shoot()
{
    return inv_shoot;
}

void Times::update_times()
{
    times -= sup;
}

void Times::update_p_shoot()
{
    p_shoot = p_shoot_clock.getElapsedTime();
}

void Times::update_inv_shoot()
{
    inv_shoot = inv_shoot_clock.getElapsedTime();
}

void Times::restart_times()
{
    times += clock.restart();
}

void Times::restart_p_shoot()
{
    p_shoot_clock.restart();
}

void Times::restart_inv_shoot()
{
    inv_shoot_clock.restart();
}

void Times::clear()
{
    inv_shoot_clock.restart();
    inv_shoot = sf::Time::Zero;
}
