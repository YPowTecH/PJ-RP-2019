// Filename:-  bg_weapons.h
//
// This crosses both client and server.  It could all be crammed into bg_public, but isolation of this type of data is best.

#ifndef __WEAPONS_H__
#define __WEAPONS_H__

typedef enum {
  WP_NONE,

  WP_STUN_BATON,
  WP_SABER,         // NOTE: lots of code assumes this is the first weapon (... which is crap) so be careful -Ste.
  WP_BRYAR_PISTOL,
  WP_BLASTER,
  WP_DISRUPTOR,
  WP_BOWCASTER,
  WP_REPEATER,
  WP_DEMP2,
  WP_FLECHETTE,
  WP_ROCKET_LAUNCHER,
  WP_THERMAL,
  WP_TRIP_MINE,
  WP_DET_PACK,
  WP_EMPLACED_GUN,
  WP_TURRET,

//  WP_GAUNTLET,
//  WP_MACHINEGUN,      // Bryar
//  WP_SHOTGUN,        // Blaster
//  WP_GRENADE_LAUNCHER,  // Thermal
//  WP_LIGHTNING,      // 
//  WP_RAILGUN,        // 
//  WP_GRAPPLING_HOOK,

  WP_NUM_WEAPONS
} weapon_t;


typedef enum //# ammo_e
{
  AMMO_NONE,
  AMMO_FORCE,    // AMMO_PHASER
  AMMO_BLASTER,  // AMMO_STARFLEET,
  AMMO_POWERCELL,  // AMMO_ALIEN,
  AMMO_METAL_BOLTS,
  AMMO_ROCKETS,
  AMMO_EMPLACED,
  AMMO_THERMAL,
  AMMO_TRIPMINE,
  AMMO_DETPACK,
  AMMO_MAX
} ammo_t;


typedef struct weaponData_s
{
//  char  classname[32];    // Spawning name

  int    ammoIndex;      // Index to proper ammo slot
  int    ammoLow;      // Count when ammo is low

  int    energyPerShot;    // Amount of energy used per shot
  int    fireTime;      // Amount of time between firings
  int    range;        // Range of weapon
  
  int    altEnergyPerShot;  // Amount of energy used for alt-fire
  int    altFireTime;    // Amount of time between alt-firings
  int    altRange;      // Range of alt-fire

  int    chargeSubTime;    // ms interval for subtracting ammo during charge
  int    altChargeSubTime;  // above for secondary

  int    chargeSub;      // amount to subtract during charge on each interval
  int    altChargeSub;    // above for secondary

  int    maxCharge;      // stop subtracting once charged for this many ms
  int    altMaxCharge;    // above for secondary
} weaponData_t;


typedef struct  ammoData_s
{
//  char  icon[32];  // Name of ammo icon file
  int    max;    // Max amount player can hold of ammo
} ammoData_t;


// MVSDK:: weaponData is now a pointer to the weaponData of the currently played version (gameplay-wise)
extern weaponData_t weaponData_1_02[WP_NUM_WEAPONS];
extern weaponData_t weaponData_1_03[WP_NUM_WEAPONS];
extern weaponData_t weaponData_1_04[WP_NUM_WEAPONS];
extern weaponData_t *weaponData;
extern ammoData_t ammoData[AMMO_MAX];


// Specific weapon information

#define FIRST_WEAPON    WP_BRYAR_PISTOL    // this is the first weapon for next and prev weapon switching
#define MAX_PLAYER_WEAPONS  WP_NUM_WEAPONS-1  // this is the max you can switch to and get with the give all.


#define DEFAULT_SHOTGUN_SPREAD  700
#define DEFAULT_SHOTGUN_COUNT  11

#define  LIGHTNING_RANGE    768





#endif//#ifndef __WEAPONS_H__
