{"changed":true,"filter":false,"title":"Hero.cpp","tooltip":"/project3/Hero.cpp","value":"#include \"Hero.h\"\n#include <iostream>\n#include <cmath>\n#include <cstdlib>\n#include <unistd.h>\n#include <stdio.h>\n#include <cctype>\n#include <string>\n#include <fstream>\n#include <string>\nusing namespace std;\n\n\n\nHero::Hero(){\n    name = \"\";\n    money = 0;\n    influence = 0;\n    armysize = 0;\n    herorow = 0;\n    herocol = 0;\n    ship = false;\n    points = 0;\n    hasbattled = false;\n}\n\n\nHero::Hero(string newname, int newmoney, int newinfluence, int newarmysize, vector<Warrior> newwarriors, int newrow, int newcol, bool newship){\n    name = newname;\n    money = newmoney;\n    influence = newinfluence;\n    armysize = newarmysize;\n    for(int i = 0; i < newwarriors.size(); i++){\n        warriors.push_back(newwarriors[i]);\n    }\n    herorow = newrow - 1;\n    herocol = newcol - 1;\n    ship = newship;\n    points = 0;\n    hasbattled = false;\n}\n\nstring Hero::getname(){\n    return name;\n}\n\nvoid Hero::setname(string newname){\n    name = newname;\n}\n\nint Hero::getmoney(){\n    return money;\n}\n\nvoid Hero::setmoney(int newmoney){\n    money = newmoney;\n}\n\nint Hero::getinfluence(){\n    return influence;\n}\n\nvoid Hero::setinfluence(int newinfluence){\n    influence = newinfluence;\n}\n\nint Hero::getarmysize(){\n    return armysize;\n}\n\nvoid Hero::setarmysize(int newarmysize){\n    armysize = newarmysize;\n}\n\nint Hero::getrow(){\n    return herorow;\n}\n\nvoid Hero::setrow(int newrow){\n    herorow = newrow;\n}\n\nint Hero::getcol(){\n    return herocol;\n}\n\nvoid Hero::setcol(int newcol){\n    herocol = newcol;\n}\n\nWarrior Hero::getwarrior(int num){\n    return warriors[num];\n}\n\nint Hero::getvectorsize(){\n    return warriors.size();\n}\n\nbool Hero::getship(){\n    return ship;\n}\n\nvoid Hero::setship(bool newship){\n    ship = newship;\n}\n\nvoid Hero::fillvector(vector<Warrior> newwarriors){\n    for(int i = 0; i < newwarriors.size(); i++){\n        warriors.push_back(newwarriors[i]);\n    }\n}\n\nint Hero::getpoints(){\n    return points;\n}\n\nvoid Hero::addpoints(int num){\n    points += num;\n}\n\nvoid Hero::addwarrior(Warrior warrior){\n    warriors.push_back(warrior);\n}\n\nvoid Hero::addmoney(int num){\n    money += num;\n}\n\nvoid Hero::addinfluence(int num){\n    influence += num;\n}\n\nvoid Hero::addarmysize(int num){\n    armysize += num;\n}\n\nbool Hero::gethasbattled(){\n    return hasbattled;\n}\n\nvoid Hero::sethasbattled(bool battle){\n    hasbattled = battle;\n}\n\nvoid Hero::removewarrior(){\n    warriors.pop_back();\n}\n\n\n//remove warrior from vector\nvoid Hero::erasewarrior(string name){\n    for(int i = 0; i < warriors.size(); i++){\n        if(warriors[i].getname() == name){\n            warriors.erase(warriors.begin() + i);\n        }\n    }\n}","undoManager":{"mark":89,"position":100,"stack":[[{"start":{"row":148,"column":7},"end":{"row":148,"column":8},"action":"insert","lines":["r"],"id":903},{"start":{"row":148,"column":8},"end":{"row":148,"column":9},"action":"insert","lines":["o"]},{"start":{"row":148,"column":9},"end":{"row":148,"column":10},"action":"insert","lines":[":"]},{"start":{"row":148,"column":10},"end":{"row":148,"column":11},"action":"insert","lines":[":"]}],[{"start":{"row":148,"column":11},"end":{"row":148,"column":12},"action":"insert","lines":["r"],"id":904},{"start":{"row":148,"column":12},"end":{"row":148,"column":13},"action":"insert","lines":["e"]},{"start":{"row":148,"column":13},"end":{"row":148,"column":14},"action":"insert","lines":["m"]}],[{"start":{"row":148,"column":11},"end":{"row":148,"column":14},"action":"remove","lines":["rem"],"id":905},{"start":{"row":148,"column":11},"end":{"row":148,"column":24},"action":"insert","lines":["removewarrior"]}],[{"start":{"row":148,"column":24},"end":{"row":148,"column":26},"action":"insert","lines":["()"],"id":906}],[{"start":{"row":148,"column":25},"end":{"row":148,"column":26},"action":"insert","lines":["i"],"id":907},{"start":{"row":148,"column":26},"end":{"row":148,"column":27},"action":"insert","lines":["n"]},{"start":{"row":148,"column":27},"end":{"row":148,"column":28},"action":"insert","lines":["t"]}],[{"start":{"row":148,"column":28},"end":{"row":148,"column":29},"action":"insert","lines":[" "],"id":908},{"start":{"row":148,"column":29},"end":{"row":148,"column":30},"action":"insert","lines":["n"]},{"start":{"row":148,"column":30},"end":{"row":148,"column":31},"action":"insert","lines":["u"]},{"start":{"row":148,"column":31},"end":{"row":148,"column":32},"action":"insert","lines":["m"]}],[{"start":{"row":148,"column":33},"end":{"row":148,"column":34},"action":"insert","lines":["{"],"id":909}],[{"start":{"row":148,"column":34},"end":{"row":150,"column":1},"action":"insert","lines":["","    ","}"],"id":910}],[{"start":{"row":148,"column":31},"end":{"row":148,"column":32},"action":"remove","lines":["m"],"id":911},{"start":{"row":148,"column":30},"end":{"row":148,"column":31},"action":"remove","lines":["u"]},{"start":{"row":148,"column":29},"end":{"row":148,"column":30},"action":"remove","lines":["n"]},{"start":{"row":148,"column":28},"end":{"row":148,"column":29},"action":"remove","lines":[" "]},{"start":{"row":148,"column":27},"end":{"row":148,"column":28},"action":"remove","lines":["t"]},{"start":{"row":148,"column":26},"end":{"row":148,"column":27},"action":"remove","lines":["n"]},{"start":{"row":148,"column":25},"end":{"row":148,"column":26},"action":"remove","lines":["i"]}],[{"start":{"row":149,"column":4},"end":{"row":149,"column":5},"action":"insert","lines":["w"],"id":912},{"start":{"row":149,"column":5},"end":{"row":149,"column":6},"action":"insert","lines":["a"]},{"start":{"row":149,"column":6},"end":{"row":149,"column":7},"action":"insert","lines":["r"]},{"start":{"row":149,"column":7},"end":{"row":149,"column":8},"action":"insert","lines":["r"]}],[{"start":{"row":149,"column":4},"end":{"row":149,"column":8},"action":"remove","lines":["warr"],"id":913},{"start":{"row":149,"column":4},"end":{"row":149,"column":12},"action":"insert","lines":["warriors"]}],[{"start":{"row":149,"column":12},"end":{"row":149,"column":13},"action":"insert","lines":["."],"id":914},{"start":{"row":149,"column":13},"end":{"row":149,"column":14},"action":"insert","lines":["p"]},{"start":{"row":149,"column":14},"end":{"row":149,"column":15},"action":"insert","lines":["o"]},{"start":{"row":149,"column":15},"end":{"row":149,"column":16},"action":"insert","lines":["p"]},{"start":{"row":149,"column":16},"end":{"row":149,"column":17},"action":"insert","lines":["_"]}],[{"start":{"row":149,"column":17},"end":{"row":149,"column":18},"action":"insert","lines":["b"],"id":915},{"start":{"row":149,"column":18},"end":{"row":149,"column":19},"action":"insert","lines":["a"]},{"start":{"row":149,"column":19},"end":{"row":149,"column":20},"action":"insert","lines":["c"]},{"start":{"row":149,"column":20},"end":{"row":149,"column":21},"action":"insert","lines":["k"]}],[{"start":{"row":149,"column":21},"end":{"row":149,"column":23},"action":"insert","lines":["()"],"id":916}],[{"start":{"row":149,"column":23},"end":{"row":149,"column":24},"action":"insert","lines":[";"],"id":917}],[{"start":{"row":150,"column":1},"end":{"row":151,"column":0},"action":"insert","lines":["",""],"id":918}],[{"start":{"row":151,"column":0},"end":{"row":151,"column":1},"action":"insert","lines":["v"],"id":919},{"start":{"row":151,"column":1},"end":{"row":151,"column":2},"action":"insert","lines":["o"]},{"start":{"row":151,"column":2},"end":{"row":151,"column":3},"action":"insert","lines":["i"]},{"start":{"row":151,"column":3},"end":{"row":151,"column":4},"action":"insert","lines":["d"]}],[{"start":{"row":151,"column":4},"end":{"row":151,"column":5},"action":"insert","lines":[" "],"id":920},{"start":{"row":151,"column":5},"end":{"row":151,"column":6},"action":"insert","lines":["h"]},{"start":{"row":151,"column":6},"end":{"row":151,"column":7},"action":"insert","lines":["E"]},{"start":{"row":151,"column":7},"end":{"row":151,"column":8},"action":"insert","lines":["R"]},{"start":{"row":151,"column":8},"end":{"row":151,"column":9},"action":"insert","lines":["O"]},{"start":{"row":151,"column":9},"end":{"row":151,"column":10},"action":"insert","lines":[":"]}],[{"start":{"row":151,"column":10},"end":{"row":151,"column":11},"action":"insert","lines":[":"],"id":921}],[{"start":{"row":151,"column":8},"end":{"row":151,"column":9},"action":"remove","lines":["O"],"id":922},{"start":{"row":151,"column":7},"end":{"row":151,"column":8},"action":"remove","lines":["R"]},{"start":{"row":151,"column":6},"end":{"row":151,"column":7},"action":"remove","lines":["E"]},{"start":{"row":151,"column":5},"end":{"row":151,"column":6},"action":"remove","lines":["h"]}],[{"start":{"row":151,"column":5},"end":{"row":151,"column":6},"action":"insert","lines":["H"],"id":923},{"start":{"row":151,"column":6},"end":{"row":151,"column":7},"action":"insert","lines":["e"]},{"start":{"row":151,"column":7},"end":{"row":151,"column":8},"action":"insert","lines":["r"]},{"start":{"row":151,"column":8},"end":{"row":151,"column":9},"action":"insert","lines":["o"]}],[{"start":{"row":151,"column":11},"end":{"row":151,"column":12},"action":"insert","lines":["e"],"id":924},{"start":{"row":151,"column":12},"end":{"row":151,"column":13},"action":"insert","lines":["r"]},{"start":{"row":151,"column":13},"end":{"row":151,"column":14},"action":"insert","lines":["a"]},{"start":{"row":151,"column":14},"end":{"row":151,"column":15},"action":"insert","lines":["s"]}],[{"start":{"row":151,"column":11},"end":{"row":151,"column":15},"action":"remove","lines":["eras"],"id":925},{"start":{"row":151,"column":11},"end":{"row":151,"column":23},"action":"insert","lines":["erasewarrior"]}],[{"start":{"row":151,"column":23},"end":{"row":151,"column":25},"action":"insert","lines":["()"],"id":926}],[{"start":{"row":151,"column":24},"end":{"row":151,"column":25},"action":"insert","lines":["i"],"id":927},{"start":{"row":151,"column":25},"end":{"row":151,"column":26},"action":"insert","lines":["n"]},{"start":{"row":151,"column":26},"end":{"row":151,"column":27},"action":"insert","lines":["t"]}],[{"start":{"row":151,"column":27},"end":{"row":151,"column":28},"action":"insert","lines":[" "],"id":928},{"start":{"row":151,"column":28},"end":{"row":151,"column":29},"action":"insert","lines":["n"]},{"start":{"row":151,"column":29},"end":{"row":151,"column":30},"action":"insert","lines":["u"]},{"start":{"row":151,"column":30},"end":{"row":151,"column":31},"action":"insert","lines":["m"]}],[{"start":{"row":151,"column":32},"end":{"row":151,"column":33},"action":"insert","lines":["{"],"id":929}],[{"start":{"row":151,"column":33},"end":{"row":153,"column":1},"action":"insert","lines":["","    ","}"],"id":930}],[{"start":{"row":152,"column":4},"end":{"row":152,"column":5},"action":"insert","lines":["w"],"id":931},{"start":{"row":152,"column":5},"end":{"row":152,"column":6},"action":"insert","lines":["a"]},{"start":{"row":152,"column":6},"end":{"row":152,"column":7},"action":"insert","lines":["r"]},{"start":{"row":152,"column":7},"end":{"row":152,"column":8},"action":"insert","lines":["r"]},{"start":{"row":152,"column":8},"end":{"row":152,"column":9},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":4},"end":{"row":152,"column":9},"action":"remove","lines":["warri"],"id":932},{"start":{"row":152,"column":4},"end":{"row":152,"column":12},"action":"insert","lines":["warriors"]}],[{"start":{"row":152,"column":12},"end":{"row":152,"column":13},"action":"insert","lines":["."],"id":933},{"start":{"row":152,"column":13},"end":{"row":152,"column":14},"action":"insert","lines":["w"]}],[{"start":{"row":152,"column":13},"end":{"row":152,"column":14},"action":"remove","lines":["w"],"id":934}],[{"start":{"row":152,"column":13},"end":{"row":152,"column":14},"action":"insert","lines":["e"],"id":935},{"start":{"row":152,"column":14},"end":{"row":152,"column":15},"action":"insert","lines":["r"]}],[{"start":{"row":152,"column":13},"end":{"row":152,"column":15},"action":"remove","lines":["er"],"id":936},{"start":{"row":152,"column":13},"end":{"row":152,"column":18},"action":"insert","lines":["erase"]}],[{"start":{"row":152,"column":18},"end":{"row":152,"column":20},"action":"insert","lines":["()"],"id":937}],[{"start":{"row":152,"column":19},"end":{"row":152,"column":20},"action":"insert","lines":["n"],"id":938},{"start":{"row":152,"column":20},"end":{"row":152,"column":21},"action":"insert","lines":["u"]},{"start":{"row":152,"column":21},"end":{"row":152,"column":22},"action":"insert","lines":["m"]}],[{"start":{"row":152,"column":23},"end":{"row":152,"column":24},"action":"insert","lines":[";"],"id":939}],[{"start":{"row":152,"column":4},"end":{"row":153,"column":0},"action":"insert","lines":["",""],"id":940},{"start":{"row":153,"column":0},"end":{"row":153,"column":4},"action":"insert","lines":["    "]},{"start":{"row":153,"column":4},"end":{"row":154,"column":0},"action":"insert","lines":["",""]},{"start":{"row":154,"column":0},"end":{"row":154,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":151,"column":30},"end":{"row":151,"column":31},"action":"remove","lines":["m"],"id":941},{"start":{"row":151,"column":29},"end":{"row":151,"column":30},"action":"remove","lines":["u"]}],[{"start":{"row":151,"column":29},"end":{"row":151,"column":30},"action":"insert","lines":["a"],"id":942},{"start":{"row":151,"column":30},"end":{"row":151,"column":31},"action":"insert","lines":["m"]},{"start":{"row":151,"column":31},"end":{"row":151,"column":32},"action":"insert","lines":["e"]}],[{"start":{"row":152,"column":4},"end":{"row":152,"column":5},"action":"insert","lines":["f"],"id":943},{"start":{"row":152,"column":5},"end":{"row":152,"column":6},"action":"insert","lines":["o"]},{"start":{"row":152,"column":6},"end":{"row":152,"column":7},"action":"insert","lines":["r"]}],[{"start":{"row":152,"column":7},"end":{"row":152,"column":9},"action":"insert","lines":["()"],"id":944}],[{"start":{"row":152,"column":8},"end":{"row":152,"column":9},"action":"insert","lines":["i"],"id":945},{"start":{"row":152,"column":9},"end":{"row":152,"column":10},"action":"insert","lines":["n"]},{"start":{"row":152,"column":10},"end":{"row":152,"column":11},"action":"insert","lines":["t"]}],[{"start":{"row":152,"column":11},"end":{"row":152,"column":12},"action":"insert","lines":[" "],"id":946},{"start":{"row":152,"column":12},"end":{"row":152,"column":13},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":13},"end":{"row":152,"column":14},"action":"insert","lines":[" "],"id":947},{"start":{"row":152,"column":14},"end":{"row":152,"column":15},"action":"insert","lines":["="]}],[{"start":{"row":152,"column":15},"end":{"row":152,"column":16},"action":"insert","lines":[" "],"id":948},{"start":{"row":152,"column":16},"end":{"row":152,"column":17},"action":"insert","lines":["0"]},{"start":{"row":152,"column":17},"end":{"row":152,"column":18},"action":"insert","lines":[";"]}],[{"start":{"row":152,"column":18},"end":{"row":152,"column":19},"action":"insert","lines":[" "],"id":949},{"start":{"row":152,"column":19},"end":{"row":152,"column":20},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":20},"end":{"row":152,"column":21},"action":"insert","lines":[" "],"id":950},{"start":{"row":152,"column":21},"end":{"row":152,"column":22},"action":"insert","lines":["<"]}],[{"start":{"row":152,"column":22},"end":{"row":152,"column":23},"action":"insert","lines":[" "],"id":951},{"start":{"row":152,"column":23},"end":{"row":152,"column":24},"action":"insert","lines":["w"]},{"start":{"row":152,"column":24},"end":{"row":152,"column":25},"action":"insert","lines":["a"]},{"start":{"row":152,"column":25},"end":{"row":152,"column":26},"action":"insert","lines":["r"]},{"start":{"row":152,"column":26},"end":{"row":152,"column":27},"action":"insert","lines":["r"]},{"start":{"row":152,"column":27},"end":{"row":152,"column":28},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":23},"end":{"row":152,"column":28},"action":"remove","lines":["warri"],"id":952},{"start":{"row":152,"column":23},"end":{"row":152,"column":31},"action":"insert","lines":["warriors"]}],[{"start":{"row":152,"column":31},"end":{"row":152,"column":32},"action":"insert","lines":["."],"id":953}],[{"start":{"row":152,"column":32},"end":{"row":152,"column":33},"action":"insert","lines":["s"],"id":954},{"start":{"row":152,"column":33},"end":{"row":152,"column":34},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":32},"end":{"row":152,"column":34},"action":"remove","lines":["si"],"id":955},{"start":{"row":152,"column":32},"end":{"row":152,"column":36},"action":"insert","lines":["size"]}],[{"start":{"row":152,"column":36},"end":{"row":152,"column":38},"action":"insert","lines":["()"],"id":956}],[{"start":{"row":152,"column":38},"end":{"row":152,"column":39},"action":"insert","lines":[";"],"id":957}],[{"start":{"row":152,"column":39},"end":{"row":152,"column":40},"action":"insert","lines":[" "],"id":958},{"start":{"row":152,"column":40},"end":{"row":152,"column":41},"action":"insert","lines":["i"]}],[{"start":{"row":152,"column":41},"end":{"row":152,"column":42},"action":"insert","lines":["+"],"id":959},{"start":{"row":152,"column":42},"end":{"row":152,"column":43},"action":"insert","lines":["+"]}],[{"start":{"row":152,"column":44},"end":{"row":152,"column":45},"action":"insert","lines":["{"],"id":960}],[{"start":{"row":152,"column":45},"end":{"row":154,"column":5},"action":"insert","lines":["","        ","    }"],"id":961}],[{"start":{"row":153,"column":8},"end":{"row":153,"column":9},"action":"insert","lines":["f"],"id":962}],[{"start":{"row":153,"column":8},"end":{"row":153,"column":9},"action":"remove","lines":["f"],"id":963}],[{"start":{"row":153,"column":8},"end":{"row":153,"column":9},"action":"insert","lines":["i"],"id":964},{"start":{"row":153,"column":9},"end":{"row":153,"column":10},"action":"insert","lines":["f"]}],[{"start":{"row":153,"column":10},"end":{"row":153,"column":11},"action":"insert","lines":[" "],"id":965}],[{"start":{"row":153,"column":10},"end":{"row":153,"column":11},"action":"remove","lines":[" "],"id":966}],[{"start":{"row":153,"column":10},"end":{"row":153,"column":12},"action":"insert","lines":["()"],"id":967}],[{"start":{"row":153,"column":11},"end":{"row":153,"column":12},"action":"insert","lines":["w"],"id":968},{"start":{"row":153,"column":12},"end":{"row":153,"column":13},"action":"insert","lines":["a"]},{"start":{"row":153,"column":13},"end":{"row":153,"column":14},"action":"insert","lines":["r"]},{"start":{"row":153,"column":14},"end":{"row":153,"column":15},"action":"insert","lines":["r"]},{"start":{"row":153,"column":15},"end":{"row":153,"column":16},"action":"insert","lines":["i"]}],[{"start":{"row":153,"column":16},"end":{"row":153,"column":17},"action":"insert","lines":["o"],"id":969},{"start":{"row":153,"column":17},"end":{"row":153,"column":18},"action":"insert","lines":["r"]},{"start":{"row":153,"column":18},"end":{"row":153,"column":19},"action":"insert","lines":["s"]},{"start":{"row":153,"column":19},"end":{"row":153,"column":20},"action":"insert","lines":["."]}],[{"start":{"row":153,"column":19},"end":{"row":153,"column":20},"action":"remove","lines":["."],"id":970}],[{"start":{"row":153,"column":19},"end":{"row":153,"column":21},"action":"insert","lines":["[]"],"id":971}],[{"start":{"row":153,"column":20},"end":{"row":153,"column":21},"action":"insert","lines":["i"],"id":972}],[{"start":{"row":153,"column":22},"end":{"row":153,"column":23},"action":"insert","lines":["."],"id":973},{"start":{"row":153,"column":23},"end":{"row":153,"column":24},"action":"insert","lines":["g"]},{"start":{"row":153,"column":24},"end":{"row":153,"column":25},"action":"insert","lines":["e"]},{"start":{"row":153,"column":25},"end":{"row":153,"column":26},"action":"insert","lines":["t"]}],[{"start":{"row":153,"column":26},"end":{"row":153,"column":27},"action":"insert","lines":["n"],"id":974}],[{"start":{"row":153,"column":23},"end":{"row":153,"column":27},"action":"remove","lines":["getn"],"id":975},{"start":{"row":153,"column":23},"end":{"row":153,"column":30},"action":"insert","lines":["getname"]}],[{"start":{"row":153,"column":30},"end":{"row":153,"column":32},"action":"insert","lines":["()"],"id":976}],[{"start":{"row":153,"column":32},"end":{"row":153,"column":33},"action":"insert","lines":[" "],"id":977},{"start":{"row":153,"column":33},"end":{"row":153,"column":34},"action":"insert","lines":["="]},{"start":{"row":153,"column":34},"end":{"row":153,"column":35},"action":"insert","lines":["="]}],[{"start":{"row":153,"column":35},"end":{"row":153,"column":36},"action":"insert","lines":[" "],"id":978}],[{"start":{"row":153,"column":36},"end":{"row":153,"column":37},"action":"insert","lines":["n"],"id":979},{"start":{"row":153,"column":37},"end":{"row":153,"column":38},"action":"insert","lines":["a"]},{"start":{"row":153,"column":38},"end":{"row":153,"column":39},"action":"insert","lines":["m"]},{"start":{"row":153,"column":39},"end":{"row":153,"column":40},"action":"insert","lines":["e"]}],[{"start":{"row":153,"column":41},"end":{"row":153,"column":42},"action":"insert","lines":["{"],"id":980}],[{"start":{"row":153,"column":42},"end":{"row":155,"column":9},"action":"insert","lines":["","            ","        }"],"id":981}],[{"start":{"row":154,"column":12},"end":{"row":154,"column":32},"action":"insert","lines":["warriors.erase(num);"],"id":982}],[{"start":{"row":154,"column":27},"end":{"row":154,"column":30},"action":"remove","lines":["num"],"id":983},{"start":{"row":154,"column":27},"end":{"row":154,"column":28},"action":"insert","lines":["i"]}],[{"start":{"row":158,"column":4},"end":{"row":158,"column":24},"action":"remove","lines":["warriors.erase(num);"],"id":984},{"start":{"row":158,"column":0},"end":{"row":158,"column":4},"action":"remove","lines":["    "]},{"start":{"row":157,"column":4},"end":{"row":158,"column":0},"action":"remove","lines":["",""]},{"start":{"row":157,"column":0},"end":{"row":157,"column":4},"action":"remove","lines":["    "]},{"start":{"row":156,"column":5},"end":{"row":157,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":151,"column":26},"end":{"row":151,"column":27},"action":"remove","lines":["t"],"id":985},{"start":{"row":151,"column":25},"end":{"row":151,"column":26},"action":"remove","lines":["n"]},{"start":{"row":151,"column":24},"end":{"row":151,"column":25},"action":"remove","lines":["i"]}],[{"start":{"row":151,"column":24},"end":{"row":151,"column":25},"action":"insert","lines":["s"],"id":986},{"start":{"row":151,"column":25},"end":{"row":151,"column":26},"action":"insert","lines":["t"]},{"start":{"row":151,"column":26},"end":{"row":151,"column":27},"action":"insert","lines":["r"]},{"start":{"row":151,"column":27},"end":{"row":151,"column":28},"action":"insert","lines":["i"]},{"start":{"row":151,"column":28},"end":{"row":151,"column":29},"action":"insert","lines":["n"]},{"start":{"row":151,"column":29},"end":{"row":151,"column":30},"action":"insert","lines":["g"]}],[{"start":{"row":154,"column":27},"end":{"row":154,"column":28},"action":"remove","lines":["i"],"id":987}],[{"start":{"row":154,"column":27},"end":{"row":154,"column":28},"action":"insert","lines":["w"],"id":988},{"start":{"row":154,"column":28},"end":{"row":154,"column":29},"action":"insert","lines":["a"]},{"start":{"row":154,"column":29},"end":{"row":154,"column":30},"action":"insert","lines":["r"]},{"start":{"row":154,"column":30},"end":{"row":154,"column":31},"action":"insert","lines":["r"]},{"start":{"row":154,"column":31},"end":{"row":154,"column":32},"action":"insert","lines":["i"]},{"start":{"row":154,"column":32},"end":{"row":154,"column":33},"action":"insert","lines":["o"]},{"start":{"row":154,"column":33},"end":{"row":154,"column":34},"action":"insert","lines":["r"]},{"start":{"row":154,"column":34},"end":{"row":154,"column":35},"action":"insert","lines":["s"]}],[{"start":{"row":154,"column":35},"end":{"row":154,"column":36},"action":"insert","lines":["."],"id":989},{"start":{"row":154,"column":36},"end":{"row":154,"column":37},"action":"insert","lines":["b"]},{"start":{"row":154,"column":37},"end":{"row":154,"column":38},"action":"insert","lines":["e"]},{"start":{"row":154,"column":38},"end":{"row":154,"column":39},"action":"insert","lines":["g"]},{"start":{"row":154,"column":39},"end":{"row":154,"column":40},"action":"insert","lines":["i"]},{"start":{"row":154,"column":40},"end":{"row":154,"column":41},"action":"insert","lines":["n"]}],[{"start":{"row":154,"column":41},"end":{"row":154,"column":43},"action":"insert","lines":["()"],"id":990}],[{"start":{"row":154,"column":43},"end":{"row":154,"column":44},"action":"insert","lines":[" "],"id":991},{"start":{"row":154,"column":44},"end":{"row":154,"column":45},"action":"insert","lines":["+"]}],[{"start":{"row":154,"column":45},"end":{"row":154,"column":46},"action":"insert","lines":[" "],"id":992},{"start":{"row":154,"column":46},"end":{"row":154,"column":47},"action":"insert","lines":["i"]}],[{"start":{"row":150,"column":1},"end":{"row":151,"column":0},"action":"insert","lines":["",""],"id":993},{"start":{"row":151,"column":0},"end":{"row":152,"column":0},"action":"insert","lines":["",""]},{"start":{"row":152,"column":0},"end":{"row":153,"column":0},"action":"insert","lines":["",""]},{"start":{"row":153,"column":0},"end":{"row":153,"column":1},"action":"insert","lines":["/"]},{"start":{"row":153,"column":1},"end":{"row":153,"column":2},"action":"insert","lines":["/"]}],[{"start":{"row":153,"column":2},"end":{"row":153,"column":3},"action":"insert","lines":["r"],"id":994},{"start":{"row":153,"column":3},"end":{"row":153,"column":4},"action":"insert","lines":["e"]},{"start":{"row":153,"column":4},"end":{"row":153,"column":5},"action":"insert","lines":["m"]},{"start":{"row":153,"column":5},"end":{"row":153,"column":6},"action":"insert","lines":["o"]},{"start":{"row":153,"column":6},"end":{"row":153,"column":7},"action":"insert","lines":["v"]},{"start":{"row":153,"column":7},"end":{"row":153,"column":8},"action":"insert","lines":["e"]}],[{"start":{"row":153,"column":8},"end":{"row":153,"column":9},"action":"insert","lines":[" "],"id":995}],[{"start":{"row":153,"column":9},"end":{"row":153,"column":10},"action":"insert","lines":["w"],"id":996}],[{"start":{"row":153,"column":9},"end":{"row":153,"column":10},"action":"remove","lines":["w"],"id":997}],[{"start":{"row":153,"column":9},"end":{"row":153,"column":10},"action":"insert","lines":["w"],"id":998},{"start":{"row":153,"column":10},"end":{"row":153,"column":11},"action":"insert","lines":["a"]},{"start":{"row":153,"column":11},"end":{"row":153,"column":12},"action":"insert","lines":["r"]},{"start":{"row":153,"column":12},"end":{"row":153,"column":13},"action":"insert","lines":["r"]},{"start":{"row":153,"column":13},"end":{"row":153,"column":14},"action":"insert","lines":["i"]},{"start":{"row":153,"column":14},"end":{"row":153,"column":15},"action":"insert","lines":["o"]},{"start":{"row":153,"column":15},"end":{"row":153,"column":16},"action":"insert","lines":["r"]}],[{"start":{"row":153,"column":16},"end":{"row":153,"column":17},"action":"insert","lines":[" "],"id":999},{"start":{"row":153,"column":17},"end":{"row":153,"column":18},"action":"insert","lines":["f"]},{"start":{"row":153,"column":18},"end":{"row":153,"column":19},"action":"insert","lines":["r"]},{"start":{"row":153,"column":19},"end":{"row":153,"column":20},"action":"insert","lines":["o"]},{"start":{"row":153,"column":20},"end":{"row":153,"column":21},"action":"insert","lines":["m"]}],[{"start":{"row":153,"column":21},"end":{"row":153,"column":22},"action":"insert","lines":[" "],"id":1000}],[{"start":{"row":153,"column":22},"end":{"row":153,"column":23},"action":"insert","lines":["v"],"id":1001},{"start":{"row":153,"column":23},"end":{"row":153,"column":24},"action":"insert","lines":["e"]},{"start":{"row":153,"column":24},"end":{"row":153,"column":25},"action":"insert","lines":["c"]},{"start":{"row":153,"column":25},"end":{"row":153,"column":26},"action":"insert","lines":["t"]},{"start":{"row":153,"column":26},"end":{"row":153,"column":27},"action":"insert","lines":["o"]},{"start":{"row":153,"column":27},"end":{"row":153,"column":28},"action":"insert","lines":["r"]}],[{"start":{"row":74,"column":0},"end":{"row":76,"column":1},"action":"remove","lines":["bool Hero::crossWater(){","    //if hero has ship return true","}"],"id":1002}],[{"start":{"row":74,"column":0},"end":{"row":75,"column":0},"action":"remove","lines":["",""],"id":1003},{"start":{"row":73,"column":0},"end":{"row":74,"column":0},"action":"remove","lines":["",""]}]]},"ace":{"folds":[],"scrolltop":183.5,"scrollleft":0,"selection":{"start":{"row":73,"column":0},"end":{"row":73,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":16,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1556163628740}