# WoM CLI

- C++17 / GCC-7
- Minilang { header: string, name: string, version: { version: options: [] } }
- Supports Docker, Virtualbox, Qemu, Virsh, Kubernetes..
- Using ncurses

## Handling errors

- Popup on boot with confirmation
- Popup on script launch

## Routine

1. Navigate through directories, select file
2. Then use parse minilang to construct object
3. Print errors if any
4. Print list of avalaible services
	- print elements keeping arborescence
5. Launch script
	- choose version
	- hook defined options
	- finally let user input additional options