use lazy_static::lazy_static;
use regex::Regex;
use std::io::prelude::*;

struct Passport {
    byr: Option<String>,
    iyr: Option<String>,
    eyr: Option<String>,
    hgt: Option<String>,
    hcl: Option<String>,
    ecl: Option<String>,
    pid: Option<String>,
    cid: Option<String>,
}

impl Passport {
    fn new() -> Passport {
        Passport {
            byr: None,
            iyr: None,
            eyr: None,
            hgt: None,
            hcl: None,
            ecl: None,
            pid: None,
            cid: None,
        }
    }

    fn parse_line(&mut self, line: String) {
        let tokens: Vec<&str> = line.as_str().split_whitespace().collect();
        for token in tokens {
            let keyval: Vec<&str> = token.split(":").collect();
            match keyval[0] {
                "byr" => {
                    self.byr = Some(keyval[1].to_owned());
                }
                "iyr" => {
                    self.iyr = Some(keyval[1].to_owned());
                }
                "eyr" => {
                    self.eyr = Some(keyval[1].to_owned());
                }
                "hgt" => {
                    self.hgt = Some(keyval[1].to_owned());
                }
                "hcl" => {
                    self.hcl = Some(keyval[1].to_owned());
                }
                "ecl" => {
                    self.ecl = Some(keyval[1].to_owned());
                }
                "pid" => {
                    self.pid = Some(keyval[1].to_owned());
                }
                "cid" => {
                    self.cid = Some(keyval[1].to_owned());
                }
                _ => {
                    println!("Unexpected passport field");
                }
            }
        }
    }

    fn is_valid_part1(&self) -> bool {
        return self.byr.is_some()
            && self.iyr.is_some()
            && self.eyr.is_some()
            && self.hgt.is_some()
            && self.hcl.is_some()
            && self.ecl.is_some()
            && self.pid.is_some();
    }

    fn is_valid_part2(&self) -> bool {
        if !self.is_valid_part1() {
            return false;
        }
        match self.byr.as_ref().unwrap().parse::<i32>() {
            Ok(v) => {
                if v < 1920 || v > 2002 {
                    return false;
                }
            }
            Err(_) => {
                return false;
            }
        }

        match self.iyr.as_ref().unwrap().parse::<i32>() {
            Ok(v) => {
                if v < 2010 || v > 2020 {
                    return false;
                }
            }
            Err(_) => {
                return false;
            }
        }

        match self.eyr.as_ref().unwrap().parse::<i32>() {
            Ok(v) => {
                if v < 2020 || v > 2030 {
                    return false;
                }
            }
            Err(_) => {
                return false;
            }
        }

        match self.hgt.as_ref().unwrap().strip_suffix("cm") {
            Some(v) => match v.parse::<i32>() {
                Ok(val) => {
                    if val < 150 || val > 193 {
                        return false;
                    }
                }
                Err(_) => {
                    return false;
                }
            },
            None => match self.hgt.as_ref().unwrap().strip_suffix("in") {
                Some(v) => match v.parse::<i32>() {
                    Ok(val) => {
                        if val < 59 || val > 76 {
                            return false;
                        }
                    }
                    Err(_) => {
                        return false;
                    }
                },
                None => {
                    return false;
                }
            },
        }

        lazy_static! {
            static ref HEX_REGEX: Regex = Regex::new(r"^#([0-9]|[a-f]){6}$").unwrap();
        }
        if !HEX_REGEX.is_match(self.hcl.as_ref().unwrap()) {
            return false;
        }

        match self.ecl.as_ref().unwrap().as_str() {
            "amb" | "blu" | "brn" | "gry" | "grn" | "hzl" | "oth" => {}
            _ => {
                return false;
            }
        }

        let pid: &str = self.pid.as_ref().unwrap();
        if pid.len() != 9 || pid.parse::<usize>().is_err() {
            return false;
        }

        return true;
    }
}

fn part1(passports: &[Passport]) -> usize {
    return passports.iter().filter(|&p| p.is_valid_part1()).count();
}

fn part2(passports: &[Passport]) -> usize {
    return passports.iter().filter(|&p| p.is_valid_part2()).count();
}

fn main() -> std::io::Result<()> {
    let input = std::fs::File::open("input")?;
    let reader = std::io::BufReader::new(input);

    let mut current: usize = 0;
    let mut passports: Vec<Passport> = Vec::new();
    passports.push(Passport::new());

    for line in reader.lines() {
        let l = line?;
        if l == "" {
            passports.push(Passport::new());
            current += 1;
        } else {
            passports[current].parse_line(l);
        }
    }
    println!("Part 1: {}", part1(&passports));
    println!("Part 2: {}", part2(&passports));
    Ok(())
}
