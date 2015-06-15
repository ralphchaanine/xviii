-------------------------------------------------------------
All unit definitions must have the following line

UNIT DEFINITION

as the first line in the file.

STRING:inf
SPRITE:INF
MAIN_TYPE:INF
FAMILY_TYPE:INF

STRING is the unit's name. Note that these also serve as unique ID's; no 2 units may have the same name.
SPRITE specifies the unit's sprite
MAIN_TYPE specifies the unit's primary type and is vital for behavior.
FAMILY_TYPE does not have any explicit effects, but is used to further classify units for bonuses.

SQUAREFORMATION:1
SQUAREFORMATIONMODIFIER:1

SQUAREFORMATION denotes whether the unit is capable of going into square formation,
while SQUAREFORMATIONMODIFIER specifies the modifier this unit gets when fighting
units in square formation (no matter the flank)

LIMBER:0
LANCER:0

These determine whether the unit is a lancer (no effect for non-cav units) and whether
the unit uses the limber mechanic.

-------------------------------------------------------------

FLANK ENTRY PROPERTIES:

Define for main types only.

FLANK
	{
		DEFINE:INF
		{
		DEFINE:FRONT:0.5
		DEFINE:SIDE: 1.5
		DEFINE:REAR: 0.5
		}

		DEFINE:CAV
		{
		DEFINE:FRONT:0.5
		DEFINE:SIDE: 0.5
		DEFINE:REAR: 0.5
		}


--------------------------------
RANGED DEFINITION PROPERTIES:

Place the range with the furthest max distance first, in descending order

RANGED
	{
	DEFINE:6,6,0.5,1,1,6
	DEFINE:3,5,1,0,1,6
	DEFINE:2,2,2,0,1,6
	}


The first and second number are the ranges
The third number is the modifier
The fourth number specifies whether the damage is fixed (1) or multiplied by your roll (0)
The fifth and sixth numbers are the thresholds that your original die roll must be in between to hit
---------------------------------
HEALING DEFINITION PROPERTIES:


HEALING
	{
	DEFINE:1,6,2
	}

First and second numbers are ranges
3rd number is the healing value

Again, descending order

------------------------------------
BONUS PROPERTIES

MELEE_BONUS
	{
		DEFINE:MAIN:INF:2,0,1,1
		DEFINE:FAMILY:HINF:3,1,1,0
	}

DEFINE:MAIN for main types
DEFINE:FAMILY for family types

(see above)

First number is modifier value, second number specifies whether it is additional or multiplicational
3rd specifies whether this bonus applies when attacking, and 4th when defending


-----------------------------------------------------------------------------------------------------


----Valid nations----

DEFINE:ALL
DEFINE:Austria
DEFINE:Bavaria
DEFINE:Commonwealth
DEFINE:Crimea
DEFINE:France
DEFINE:GBR
DEFINE:Imereti
DEFINE:Moldavia
DEFINE:Ottomans
DEFINE:Portugal
DEFINE:Prussia
DEFINE:Russia
DEFINE:Saxony
DEFINE:Spain
DEFINE:Sweden
DEFINE:Venice
DEFINE:Wallachia
DEFINE:Persia

----Valid sprites----

DEFINE:INF			-Infantry
DEFINE:CAV			-Cavalry
DEFINE:CUIR		-Cuirassier
DEFINE:LCAV		-Light Cavalry
DEFINE:DRAG		-Dragoon
DEFINE:ART 		-Artillery
DEFINE:MOR 		-Mortar
DEFINE:GEN			-General
DEFINE:GRE			-Grenadier
DEFINE:LINF		-Light Infantry
DEFINE:SAP			-Sapper/Engineer
DEFINE:HINF		-Heavy Infantry
DEFINE:ARTGUARD	-Artillery Guard
DEFINE:PIKE		-Pikeman
DEFINE:LAN			-Lancer
DEFINE:ARMLAN		-Armoured Lancer
DEFINE:IRR			-Irregular
DEFINE:HARCH		-Horse Archer
DEFINE:LART		-Light Artillery
DEFINE:LDRAG		-Light Dragoon

----Valid units----

DEFINE:INF 		-Infantry
DEFINE:CAV 		-Cavalry
DEFINE:ART 		-Artillery
DEFINE:MOR 		-Mortar
DEFINE:GEN 		-General (Cavalry)
DEFINE:ARTGUARD 	-Artillery Guard

----Valid Family Types---

DEFINE:LINF 		-Light Infantry
DEFINE:INF 		-Infantry
DEFINE:HINF 		-Heavy Infantry
DEFINE:CAV 		-Cavalry
DEFINE:ART 		-Artillery
DEFINE:IRR 		-Irregulars

----Valid Eras---
DEFINE:ALL
DEFINE:MID
DEFINE:EARLY
DEFINE:LATE