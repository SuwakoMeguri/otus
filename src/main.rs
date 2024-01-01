pub fn main() {
    let thermometer = Thermometer {
        temperature: 20
    };
    let mut socket = Socket {
        description: String::from("Some description"),
        power: 0,
    };

    println!("{}", thermometer.curr_temp());

    println!("{}", socket.description());
    socket.power_on();
    println!("{}", socket.get_power());
    socket.power_off();
    println!("{}", socket.get_power());
}

struct Thermometer {
    temperature: i32,
}

struct Socket {
    description: String,
    power: i32,
}

impl Thermometer {
    fn curr_temp(&self) -> i32 {
        self.temperature
    }
}

impl Socket {
    fn power_on(&mut self) {
        self.power = 220;
    }

    fn power_off(&mut self) {
        self.power = 0;
    }

    fn get_power(&self) -> i32 {
        self.power
    }

    fn description(&self) -> &str {
        &self.description
    }
}
