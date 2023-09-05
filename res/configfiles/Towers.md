
# Towers
## Summary
Towers are in tower defense the things used to defend the final tower or what is otherwise known as the base. A tower can be bought  by a player for a certain amount of money to be placed on the playing field. Once placed it will attack enemies who come in range of the tower and shoot bullets at them that deal damage. A tower can be upgraded and sold by clicking on them and pressing the upgrade or delete button. 

<br>

<details open>
<summary> An example of how towers are defined</summary>

---
```json
"Towers": [
    {
        "Name": "Lazer UFO",
        "Damage": 5,
        "Range": 2,
        "Firerate": 20,
        "Cost" : 170,
        "textureFile": "../res/images/ufoRed.png",
        "bulletTexture": "../res/images/laserRed.png"
    },
    {
        "Name": "Water UFO",
        "Damage": 3,
        "Range": 4,
        "Firerate": 30,
        "Cost" : 350,
        "textureFile": "../res/images/ufoBlue.png",
        "bulletTexture": "../res/images/laserBlue.png"
    }
]
```
</details>

<br>

## How to create a new tower

<details>
<summary> Setting a towers Name :fountain_pen: </summary>
Add a property "Name" to your tower and give it a value of your desired name.
<br>

* Default value is None
* Type value is string

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO"
    }
]
```

</details>
<br>

<details>
<summary> Setting a towers damage :boom: </summary>

Add a propery "Damage" and set the value to your desired damage.
<br>

* Default value is 0
* Type value is float

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO",
    "Damage":10
    }
]
```

</details>
<br>

<details>
<summary> Setting a tower fire rate :alarm_clock: </summary>

Add a propery "Firerate" and set the value to your desired fire rate.
<br>

* The fire rate is in rounds per minute
* Default value is 0
* Type value is float

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO",
    "Damage":10,
    "Firerate":20
    }
]
```

</details>
<br>

<details>
<summary> Setting a towers cost :moneybag: </summary>

Add a propery "Cost" and set the value to your desired price.
<br>

* Default value is 0
* Type value is unsigned int

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO",
    "Damage":10,
    "Firerate":20,
    "Cost":100
    }
]
```

</details>
<br>

<details>
<summary> Setting a towers texture :framed_picture: </summary>

Add a propery "TextureFile" and set the value to your desired texture's file location.
<br>

* There is no default value and crashes the game if none is provided
* Type value is string

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO",
    "Damage":10,
    "Firerate":20,
    "Cost":100,
    "textureFile": "../res/images/ufoRed.png"
    }
]
```

</details>
<br>

<details>
<summary> Setting a towers bullet texture :bow_and_arrow: </summary>

Add a propery "BulletTexture" and set the value to your desired texture's file location.
<br>

* There is no default value and crashes the game if none is provided
* Type value is string

```json
"Towers": [
    {...},
    {
    "Name": "Water UFO",
    "Damage":10,
    "Firerate":20,
    "Cost":100,
    "textureFile": "../res/images/ufoRed.png",
    "bulletTexture": "../res/images/laserBlue.png"
    }
]
```

