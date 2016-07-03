VALID_ARCHS="armv7 arm64"
TARGET_FILE=NMAKit
ARCHS="$(lipo -info ${TARGET_FILE} | rev | cut -d ':' -f1 | rev)"

echo "current archs are $ARCHS"
for ARCH in $ARCHS; do
    if ! [[ "${VALID_ARCHS}" == *"$ARCH"* ]]; then
        echo "stripping $ARCH"
        lipo -remove $ARCH -output $TARGET_FILE $TARGET_FILE || exit 1
    fi
done
echo "processed archs are $(lipo -info ${TARGET_FILE} | rev | cut -d ':' -f1 | rev)"
