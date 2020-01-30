# Waves

## Summary
In Tower Defense [Enemies](/DaanZVW/TowerDefense/blob/master/res/configfiles/Enemies.md) come in waves trying to destroy the [Base](/DaanZVW/TowerDefense/blob/master/res/configfiles/Base.md). It is the players objective to stop these waves. Each wave can be defined in how many, how quickly and what type of [Enemies](/DaanZVW/TowerDefense/blob/master/res/configfiles/Enemies.md) will come.

<br>
<details open>
<summary> An example of how waves are defined</summary>

```json
"waves": [
    [
        {
             "name": "enemy1",
            "amount": 40,
            "spawntime": 1
        }
    ],
        [
        {
            "amount": 20,
            "name": "enemy1",
            "spawntime": 1
        },
        {
            "name": "enemy2",
            "amount": 20,
            "spawntime": 0.5
        },
        {
            "amount": 20,
            "name": "enemy1",
            "spawntime": 1
        }
    ]
]
```
</details>

<br>

## How to create a new tower

<details>
<summary> Creating waves :fountain_pen: </summary>
Add a property "waves" and follow the other steps to configure it further.
<br>

* If this is not defined no enemies will spawn.


```json
"waves": [...]
```

</details>
<br>

<details>
<summary> Creating a wave :fountain_pen: </summary>
Add an item to "waves" for every wave you want and follow the other steps to configure it further.
<br>

* If this is not defined no enemies will spawn.
* Every item is one wave.
* The waves spawn in the order you define it in.


```json
"waves": [
    [...],
    [...]
]
```

</details>
<br>

<details>
<summary> Spawning an enemy in a wave :fountain_pen: </summary>
Add an item to an item "waves" for every type you want and follow the other steps to configure it further.
<br>

* If this is not defined no enemies will spawn.
* You can add 1 or more enemy types in a wave.
* You can add the same enemy in the same wave multiple times to achieve mixed spawning of enemies.


```json
"waves": [
    [...],
    [
        {...},
        {...}
    ]
]
```

</details>
<br>

<details>
<summary> Specifying an enemy :fountain_pen: </summary>
Add a property "name" to an item in a wave item for every type you want.
<br>

* If the enemy it's name does not exist in enemyChar nothing will spawn.
* If this is not defined no enemies will spawn.
* The value is a string


```json
"waves": [
    [...],
    [
        {...},
        {
            "name":"enemy1"
        }
    ]
]
```

</details>
<br>

<details>
<summary> Specifying an enemy amount :1234: </summary>
Add a property "amout" to an item in a wave item to specify how many of that type you want to spawn in that wave.
<br>

* The default value is 0.
* The value is an unsigned int


```json
"waves": [
    [...],
    [
        {...},
        {
            "name":"enemy1",
            "amount":1
        }
    ]
]
```

</details>
<br>

<details>
<summary> Specifying an enemy it's spawn time :hourglass: </summary>
Add a property "spawnTime" to an item in a wave item for how fast you want the enemies to spawn after eachother.
<br>

* The spawn time is defined in seconds
* The default value is 0
* The value is a float


```json
"waves": [
    [...],
    [
        {...},
        {
            "name":"enemy1",
            "amount":1,
            "spawntime": 1
        }
    ]
]
```

</details>
<br>


## Links
[Base](/DaanZVW/TowerDefense/blob/master/res/configfiles/Base.md)
<br>
[Waves](/DaanZVW/TowerDefense/blob/master/res/configfiles/Waves.md)
<br>
[Enemies](/DaanZVW/TowerDefense/blob/master/res/configfiles/Enemies.md)
<br>
[Towers](/DaanZVW/TowerDefense/blob/master/res/configfiles/Towers.md)
<br>
[Map](/DaanZVW/TowerDefense/blob/master/res/configfiles/Map.md)

