
# Enemies

## Summary
In Tower Defense there are enemies that follow a prefined path to deal damage to your base. The goal of the player is to defend that [Base](/res/configfiles/Base.md) by killing the enemies.
All enemies are defined within the config json with predefined types of attributes. Here will be explained how to add and configure them



<details open>
<summary>An example of how enemies are defined</summary>

```json
"enemyChar":{
    "enemy_name": 
        {
        "damage": 10,
        "speed": 1,
        "health": 20,
        "reward": 3,
        "textureFile": "../res/images/spaceinvader.png",
        "texturepos": [
            {
            "positionX": 0,
            "positionY": 0,
            "sizeX": 32,
            "sizeY": 32
            },
            {
            "positionX": 32,
            "positionY": 0,
            "sizeX": 32,
            "sizeY": 32
            }
        ]
    }
}
```
</details>


<br>

## How to create a new tower


<details>
<summary> 
Adding a new enemy :new:
</summary>

Adding a new enemy can be done by adding a new JSON object to the property "enemyChar" with your own unique name.

```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{...}
    }
}
```
</details>
<br>

<details>
<summary> 
Setting damage of an enemy :knife:
</summary>
Add a propery "damage" and set the value to your desired damage.
<br>

* The default value is 0.
* The value type is float.

```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{
            "damage":10
        }
    }
}
```
</details>
<br>


<details>
<summary> 
Setting health of an enemy :two_hearts:
</summary>
Add a propery "health" and set the value to your desired health.
<br>

* The default value is 0.
* The value type is float.

```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{
            "damage":10,
            "health":10
        }
    }
}
```

</details>
<br>
<details>
<summary> 
Setting speed of an enemy :athletic_shoe:
</summary>

Add a propery "speed" and set the value to your desired speed.
<br>

* Speed is defined in tiles per second.
* The default value is 0.
* The value type is float.

```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{
            "damage":10,
            "health":10,
            "speed": 2
        }
    }
}
```

</details>
<br>


<details>
<summary> 
Setting reward of an enemy :moneybag:
</summary>
Add a propery "health" and set the value to your desired health.
<br>

* The default value is 0.
* The value type is unsigned int.


```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{
            "damage":10,
            "health":10,
            "speed": 2,
            "reward":10
        }
    }
}
```

</details>
<br>

<details>
<summary> 
Setting texture of an enemy :framed_picture:
</summary>
Add a propery "texture" and set the value to your desired texture's filepath.
<br>

* When the program cannot find the texture, the texture will be a white square.
* This does not have a default value and will crash if you don't define it.
* The value type is string.

```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{
            "damage":10,
            "health":10,
            "speed": 2,
            "reward":10,
            "textureFile": "../res/images/spaceinvader.png",
        }
    }
}
```

</details>
<br>

<details>
<summary> 
Setting texture positions/animations of an enemy  ---OPTIONAL--- :framed_picture: :framed_picture:
</summary>
Add a propery "texturePos" and set the value to your desired texture position and or sprites.
<br>

* There is no default value. When this is not defined it uses the full size of the texture.
* The value type is an item containing the x y coordinates and the size.
* When you add multiple items it cycles between them whilst playing.
* The x y coordinates and size are in pixels.

```json
"enemyChar":{
    "otherEnemy":{...},
    "yourEnemy":{
       "damage":10,
        "health":10,
        "speed": 2,
        "reward":10,
        "textureFile": "../res/images/spaceinvader.png",
        "texturepos": [
            {
            "positionX": 0,
            "positionY": 0,
            "sizeX": 32,
            "sizeY": 32
            },
            {
            "positionX": 32,
            "positionY": 0,
            "sizeX": 32,
            "sizeY": 32
            }
        ]
    }
}
```

</details>

<br>

## Links

[Base](/res/configfiles/Base.md)
<br>
[Waves](/res/configfiles/Waves.md)
<br>
[Towers](/res/configfiles/Towers.md)
<br>
[Map](/res/configfiles/Map.md)

