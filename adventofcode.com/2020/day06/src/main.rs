use std::io::prelude::*;

struct Group {
    answers: [bool; 26],
    answers2: [bool; 26],
}

impl Group {
    fn new() -> Self {
        Group {
            answers: [false; 26],
            answers2: [true; 26],
        }
    }

    fn parse_line(&mut self, ticket: String) {
        let mut answer: [bool; 26] = [false; 26];
        for byte in ticket.as_bytes() {
            self.answers[*byte as usize - 97] = true;
            answer[*byte as usize - 97] = true;
        }

        for i in 0..26 {
            if !answer[i] {
                self.answers2[i] = false;
            }
        }
    }

    fn get_true_count(&self) -> (usize, usize) {
        let mut count: usize = 0;
        let mut count2: usize = 0;
        for i in 0..26 {
            if self.answers[i] {
                count += 1;
            }
            if self.answers2[i] {
                count2 += 1;
            }
        }

        return (count, count2);
    }
}

fn part1(groups: &[Group]) -> usize {
    return groups.iter().map(|g| g.get_true_count().0).sum();
}

fn part2(groups: &[Group]) -> usize {
    return groups.iter().map(|g| g.get_true_count().1).sum();
}

fn main() -> std::io::Result<()> {
    let input = std::fs::File::open("input")?;
    let reader = std::io::BufReader::new(input);

    let mut groups: Vec<Group> = Vec::new();
    groups.push(Group::new());
    let mut current: usize = 0;
    for line in reader.lines() {
        let l = line?;
        if l == "" {
            groups.push(Group::new());
            current += 1;
        } else {
            groups[current].parse_line(l);
        }
    }

    println!("Part 1: {}", part1(&groups));
    println!("Part 2: {}", part2(&groups));
    Ok(())
}
