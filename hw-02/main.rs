use std::{io, net::Ipv4Addr};

fn main() {
    let ip_addresses = get_all_ip_addresses();

    let without_filter = |_: [u8; 4]| true;
    let starting_with_1 = |octets: [u8; 4]| octets.starts_with(&[1]);
    let starting_with_46_70 = |octets: [u8; 4]| octets.starts_with(&[46, 70]);
    let containing_46 = |octets: [u8; 4]| octets.contains(&46);

    print_selected(&ip_addresses, without_filter);
    print_selected(&ip_addresses, starting_with_1);
    print_selected(&ip_addresses, starting_with_46_70);
    print_selected(&ip_addresses, containing_46);
}

fn print_selected(ip_addresses: &[Ipv4Addr], predicate: fn([u8; 4]) -> bool) {
    ip_addresses
        .iter()
        .filter(|ip_address| predicate(ip_address.octets()))
        .for_each(|ip_address| println!("{}", ip_address));
}

fn get_all_ip_addresses() -> Vec<Ipv4Addr> {
    let mut ip_addresses = io::stdin()
        .lines()
        .map(|line| {
            line.expect("Line should be valid string")
                .split_whitespace()
                .next()
                .expect("Line should be present after split")
                .parse::<Ipv4Addr>()
                .expect("Line should be valid IP address")
        })
        .collect::<Vec<Ipv4Addr>>()
    ip_addresses.sort_by(|first, second| second.cmp(first));

    ip_addresses
}
