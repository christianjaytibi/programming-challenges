/*
*   Problem: Robot control
*   Problem Link: https://hyperskill.org/learn/step/11522
* */

class Move {
    public static void moveRobot(Robot robot, int toX, int toY) {

        // Calculate distance between initial x-coordinate and destination x-coordinate
        int xDistance = Math.abs(robot.getX() - toX);
        if (xDistance != 0) {
            // Rotate the robot to prepare moving along the x-axis
            Direction targetDirection = robot.getX() > toX ? Direction.LEFT : Direction.RIGHT;
            rotateRobot(robot, targetDirection);
            // Move the robot forward n-times
            moveRobotForward(robot, xDistance);
        }

        // Calculate distance between y-coordinate and destination y-coordinate
        int yDistance = Math.abs(robot.getY() - toY);
        if (yDistance != 0) {
            // Rotate the robot to prepare moving along the y-axis
            Direction targetDirection = robot.getY() > toY ? Direction.DOWN : Direction.UP;
            rotateRobot(robot, targetDirection);
            // Move the robot forward n-times
            moveRobotForward(robot, yDistance);
        }

    }

    static void rotateRobot(Robot robot, Direction targetDirection) {
        if (robot.getDirection() == targetDirection) {
            return;
        }

        int offset = targetDirection.ordinal();
        int clockWiseDist = Math.floorMod(offset - robot.getDirection().ordinal(), 4);
        int counterClockwiseDist = Math.floorMod(robot.getDirection().ordinal() - offset, 4);
        boolean isRotationClockwise = clockWiseDist < counterClockwiseDist;
        int numRotations = Math.min(clockWiseDist, counterClockwiseDist);

        Runnable turnRobot = isRotationClockwise ? robot::turnRight : robot::turnLeft;
        for (int i = 0; i < numRotations; i++) {
            turnRobot.run();
        }
    }

    static void moveRobotForward(Robot robot, int numOfSteps) {
        for (int i = 0; i < numOfSteps; i++) {
            robot.stepForward();
        }
    }
}


enum Direction {
    UP(0, 1),
    RIGHT(1, 0),
    DOWN(0, -1),
    LEFT(-1, 0);

    private final int dx;
    private final int dy;

    Direction(int dx, int dy) {
        this.dx = dx;
        this.dy = dy;
    }

    public Direction turnLeft() {
        return switch (this) {
            case UP -> LEFT;
            case DOWN -> RIGHT;
            case LEFT -> DOWN;
            case RIGHT -> UP;
            default -> throw new IllegalStateException();
        };
    }

    public Direction turnRight() {
        return switch (this) {
            case UP -> RIGHT;
            case DOWN -> LEFT;
            case LEFT -> UP;
            case RIGHT -> DOWN;
            default -> throw new IllegalStateException();
        };
    }

    public int dx() {
        return dx;
    }

    public int dy() {
        return dy;
    }
}

class Robot {
    private int x;
    private int y;
    private Direction direction;

    public Robot(int x, int y, Direction direction) {
        this.x = x;
        this.y = y;
        this.direction = direction;
    }

    public void turnLeft() {
        direction = direction.turnLeft();
    }

    public void turnRight() {
        direction = direction.turnRight();
    }

    public void stepForward() {
        x += direction.dx();
        y += direction.dy();
    }

    public Direction getDirection() {
        return direction;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public String toString() {
        return "Robot(" + x + ", " + y + ")";
    }
}
