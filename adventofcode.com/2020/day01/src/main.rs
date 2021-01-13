fn main() {
    let input = std::fs::read_to_string("input").unwrap();
    let mut values = input
        .lines()
        .map(|line| line.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    // part1: a*b is maximized when a,b are closer to each other
    let mut ans: usize = 0;
    let mut found: [bool; 2021] = [false; 2021];

    for v in &values {
        if found[2020 - v] && ans < std::cmp::min(2020 - *v, *v) {
            ans = std::cmp::min(2020 - *v, *v);
        }
        found[*v] = true;
    }
    println!("Answer of part1: {}", ans * (2020 - ans));

    values.sort_unstable();
    for i in 0..values.len() {
        for j in i..values.len() {
            if values[i] + values[j] > 2020 {
                break;
            }

            for k in j..values.len() {
                let sum = values[i] + values[j] + values[k];
                if sum == 2020 {
                    println!("Answer of part2: {}", values[i] * values[j] * values[k]);
                } else if sum > 2020 {
                    break;
                }
            }
        }
    }
}
