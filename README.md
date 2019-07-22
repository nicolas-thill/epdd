# epdd

## Build an OpenWrt package

1. Clone this repository
```
clone https://github.com/psycho-nico/epdd.git
```
2. Download appropriate SDK
```
wget https://downloads.openwrt.org/releases/18.06.4/targets/x86/64/openwrt-sdk-18.06.4-x86-64_gcc-7.3.0_musl.Linux-x86_64.tar.xz
```
3. Extract SDK
```
tar -Jxf openwrt-sdk-18.06.4-x86-64_gcc-7.3.0_musl.Linux-x86_64.tar.xz
```
4. Enter SDK directory
```
cd openwrt-sdk-18.06.4-x86-64_gcc-7.3.0_musl.Linux-x86_64
```
5. Configure SDK
```
make menuconfig
```
6. Prepare feeds 
```
cp feeds.conf.default feeds.conf
```
7. Add this repository to the feeds
```
echo "src-link epdd_pkg ../../epdd/pkg/openwrt" | tee -a feeds.conf
```
8. Update feeds
```
./scripts/feeds update
```
9. Add epdd package
```
./scripts/feeds install -d m epdd
```
10. Build epdd package
```
make package/feeds/epdd_pkg/epdd/compile
```
