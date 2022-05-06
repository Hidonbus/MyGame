#ifndef BATLLE_H
#define BATTLE_H
void battle_interface(character* hero, int temp_hp, enemy& villain);
void battle(character* hero, int stage);
int hero_attack(character* hero,int& temp_hp, enemy& villain);
int villain_attack(character* hero,int& temp_hp, enemy& villain);
void check_if_dead(character* hero, enemy& villain, int& temp_hp, char& onoff, int& who_died, character copy);
void hero_regen(character*hero, int&temp_hp, enemy& villain);
int boss_battle(character*hero);
#endif