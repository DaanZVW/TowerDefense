
## Adding enemies

### All enemies are defined within the config json with predefined types of attributes. Here will be explained how to add and configure them


This is an example of how an enemy can be defined
------

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


Adding a new enemy can be done by adding a new JSON object to the property "enemyChar" with your own unique name. 
```json
"enemyChar":{
    "enemyChar":{
        "otherEnemy":{...},
        "yourEnemy":{...}
    }
}
```
In your new enemy object you can define it's damage as a float which is 0 by default.
You can add it by adding the property "damage" to your enemy property.
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

For defining its health you need to add the property health to your enemy property. You can do that by adding "health" to the enemy property which will be interpreted as a float with a default value of 0.
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

The enemy also has a speed which is in tiles per second. It is interpreted as a float, by default 0 and can be added as seen below.
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

When an enemy dies it is prefered that the player gets rewarded some money which can be defined per enemy type. It is interpreted as an unsigned int, by default 0 and can be added as seen below.
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

What distinguishes an enemy the most is it's texture. If it's not defined the program will produce an error. If the texture is defined but does not exist the texture will be a white square. You can add it by defining the textureFile propery with it's value being the file location in a string as seen below.
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

One picture might be enough for you but if you want to add animations, that is possible with sprites. This is an optional addition and can be added by having the property "texturePos" with an array containing 1 or more items. Each item in the array needs x y coordinates in pixels of the sprite of the top left corner and the size of the sprite you want. An example of this can be seen below.
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

If you followed all these steps you just added a new enemy which you can use for defining waves which is explained [here](google.com)
