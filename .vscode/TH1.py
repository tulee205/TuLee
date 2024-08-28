print("_______ Bài 1")
# Bài 1
class Shop:
    def __init__(self, name, items):
        self.name = name
        self.items = items
    def get_items_count(self):
        return len(self.items)
shop = Shop("My shop",["Minh","Tu","DucBo"])
print(shop.get_items_count()) 

print("_______","Bai 2")
# Bài 2
class Hero:
    def __init__(self, name, health):
        self.name = name
        self.health = health
    def defend(self, damage):
        self.damage = damage
        self.health -= damage
        if self.health <= 0:
            return f"{self.name} was defeated."
    def heal(self, amount):
        self.amount = amount
        self.health += amount
hero = Hero("Minh",100)
print(hero.defend(20))
hero.heal(10)
print(hero.defend(30))
print(hero.defend(20))

print("_______", "Bai 3")
# Bài 3
class Employee:
    def __init__(self, id, name, salary):
        self.id = id
        self.name = name
        self.salary = salary
    def get_full_name(self):
        return f"My name is {self.name}."
    def tongluong(self):
        s = self.salary*12
        print(f"Tổng lương là {s}.")
    def luongtang(self, amount):
        self.amount =amount
        self.salary += amount
        return f"Mức lương sau khi tăng là {self.salary}."
employee = Employee(18052005, 'Minh', 1000)
print(employee.get_full_name())
print(employee.luongtang(1000))
print(employee.tongluong())

print("_______ Bài 4")
# Bài 4 
class Cup:
    def __init__(self, size, quantity):
        self.size = size
        self.quantity = quantity
    def fill(self, mm):
        self.mm = mm
        self.quantity += mm
        if self.size - self.quantity == 0:
            print(f"Cup is fulled")
    def status(self):
        return abs(self.size - self.quantity)
cup = Cup(100, 50)
print(cup.status())
cup.fill(40)
cup.fill(20)
print(cup.status())

print("_______Bài 5")
class Flower:
    def __init__(self, name, water_requirements):
        self.name = name
        self.water_requirements = water_requirements
        self.is_happy = False
    def water(self, quantity):
        self.quantity = quantity
        self.is_happy=self.water_requirements == self.quantity
    def status(self):
        if self.is_happy:
            return f"{self.name} is happy."
        else:
            return f"{self.name} is not happy."
flower = Flower("Lilly", 60)
flower.water(50)
print(flower.status())
flower.water(60)
print(flower.status())
flower.water(100)
print(flower.status())

print("______Bai 6")
# Bai 6
class SteamUser:
    def __init__(self, username, games):
        self.username = username
        self.games = games
        self.played_hours = 0
    def play(self, game, hours):
        self.game = game
        self.hours = hours
        if self.game in self.games:
            self.played_hours += hours
            return f"{self.username} playing {self.game}."
        else:
            return f"{self.game} is not in library"
    def buy_game(self, game):
        if game not in self.games:
            self.games.append(game)
            return f"{self.username} bought {game}."
        else:
            return f"{game} already in your library."
    def status(self):
        games_count = len(self.games)
        return f"{self.username} has {games_count} games. Total play time: {self.played_hours}"

user = SteamUser("Peter", ["Rainbow Six Siege", "CS:GO", "Fortnite"])
print(user.play("Fortnite", 3))
print(user.play("Oxygen Not Included", 5))
print(user.buy_game("CS:GO"))
print(user.buy_game("Oxygen Not Included"))
print(user.play("Oxygen Not Included", 6))
print(user.status())

print('____ BÀi 7')
# Bài 7
class Programmer:
    def __init__(self, name, language, skills):
        self.name = name
        self.language = language
        self.skills = skills
    def watch_course(self,course_name, course_language, skills_earned):
        if course_language == self.language:
            self.skills += skills_earned
            return f"{self.name} watched {course_name}."
        else:
            return f"{self.name} doesn't know {course_language}."
    def change_language(self, new_language, skill_needed):
        if new_language != self.language and self.skills >= skill_needed:
            previous_language = self.language
            self.language = new_language
            print(f"{self.name} switched from {previous_language} to {new_language}.")
        elif new_language == self.language:
            print(f"{self.name} already knows {self.language}.")
        else:
            return f"{self.name} needs {skill_needed - self.skills} more skills"
programmer = Programmer("John", "Java", 50)
print(programmer.watch_course("Python Masterclass", "Python", 84))
print(programmer.change_language("Java", 30))
print(programmer.change_language("Python", 100))
print(programmer.watch_course("Java: zero to hero", "Java", 50))
print(programmer.change_language("Python", 100))
print(programmer.watch_course("Python Masterclass", "Python", 84))

print("______Bài 8")
# Bài 8
class Pokemon:
    def __init__(self, name, health):
        self.name = name
        self.health = health
    def pokemon_details(self):
        return f"{self.name} with health {self.health}."
class Trainer:
    def __init__(trainer, name, pokemons):
        trainer.name = name
        trainer.pokemons = pokemons
        len(trainer.pokemons)
    def add_pokemon(pokemon):
