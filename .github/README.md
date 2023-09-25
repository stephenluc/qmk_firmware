# Setup Environment
Either follow [QMK Tutorial Guide](https://docs.qmk.fm/#/newbs) or trust past self
```
brew install qmk/qmk/qmk
git clone git@github.com:stephenluc/qmk_firmware.git
cd qmk_firmware
qmk setup
```

# Updating Fork
```
# Make sure we are tracking upstream
git remote add upstream https://github.com/qmk/qmk_firmware.git

# Fetching updates from upstream and merging with master
git checkout master
git fetch upstream
git pull upstream master
git push origin master

# Updating staging branch with new updates from master
git checkout stephen/keyboards
git merge master
git push
```
